const listContainer = document.getElementById('listContainer');

//L9lib a3mo l9lib asidi, makhedamach 100% makatkhlikch tdir display les infos ATTENTION IMPORTANT!
function toggleFrames() {
  const frame1 = document.querySelector('.frame1');
  const frame2 = document.querySelector('.frame2');
  frame1.classList.toggle('frame1');
  frame1.classList.toggle('frame2');
  frame2.classList.toggle('frame1');
  frame2.classList.toggle('frame2');
}
//Base données initial 
 dict = {
  "Développement Web": ["", "", "Le développement Web désigne de manière générale les tâches associées au développement de sites Web destinés à être hébergés via un intranet ou Internet."],
  "oppa": ["", "", "Le développement Web désigne de manière générale les tâches associées au développement de sites Web destinés à être hébergés via un intranet ou Internet."],
  "Côté client": ["Développement Web", "", "fait référence à tout ce qui est affiché ou se déroule dans une application Web sur le client (appareil de l'utilisateur final)"],
  "Côté Serveur": ["Développement Web", "", "Description for Côté Serveur"],
  "Côté": ["oppa", "", "Description for Côté Serveur"],

  "HTML": ["Côté client", "https://upload.wikimedia.org/wikipedia/commons/thumb/6/61/HTML5_logo_and_wordmark.svg/180px-HTML5_logo_and_wordmark.svg.png", "HyperText Markup Language: langage de balisage conçu pour représenter les pages web."],
  "CSS": ["Côté client", "https://upload.wikimedia.org/wikipedia/commons/thumb/d5/CSS3_logo_and_wordmark.svg/800px-CSS3_logo_and_wordmark.svg.png", "Feuilles de style en cascade: est l'un des langages principaux du Web ouvert et a été standardisé par le W3C"],
  "PHP": ["Côté Serveur", "", "Hypertext Preprocessor: langage de programmation libre, principalement utilisé pour produire des pages Web dynamiques via un serveur web."],
  "PP": ["Côté", "php.jpg", "Hypertext Preprocessor: langage de programmation libre, principalement utilisé pour produire des pages Web dynamiques via un serveur web."]
};
function buildHierarchy(topParent, type) {

  var ol = document.createElement('ol');
  ol.type = type;
  
  Object.keys(dict).forEach(function (key) {
    if (dict[key][0] === topParent) {
      var li = document.createElement('li');
      var summaryLi = document.createElement('li');
      var summary = document.createElement('summary');
      summary.textContent = key;
      summaryLi.appendChild(summary);
      li.appendChild(summaryLi);
      ol.classList.add('collapsible');
      var summary = document.createElement('summary');
      var details = document.createElement('details');
      details.appendChild(summary);
      details.appendChild(ol);

      const removeButton = document.createElement('button');
      removeButton.setAttribute('type', 'button');
      removeButton.addEventListener('click', function () {
        const keyToRemove = this.parentNode.querySelector('summary').textContent;
        removeElement(keyToRemove);
      });
      removeButton.textContent = '⋫ ';
      li.appendChild(removeButton);

     var addabButton = document.createElement('button');
     addabButton.setAttribute('type', 'button');
     addabButton.addEventListener('click', function () {
      let choice=1;
      addNewItem(key, choice);
     });
     addabButton.textContent = '⊷';
     li.appendChild(addabButton);
     
     
     var addblButton = document.createElement('button');
     addblButton.setAttribute('type', 'button');
     addblButton.addEventListener('click', function () {
      let choice=2;
      addNewItem(key, choice);
  });
     addblButton.textContent = '⊶';
     li.appendChild(addblButton);
      ol.appendChild(li);
      


      var children = buildHierarchy(key, "1");

      if (children) {
        li.appendChild(children);
      } else {
        if (Object.keys(dict).find(childKey => dict[childKey][0] === key)) {
          var childLi = document.createElement('li');
          childLi.textContent = key;
          li.appendChild(childLi);
        }
      }
      ol.appendChild(li);
      
    }

  });

  if (ol.childNodes.length > 0) {
    if (type === "I" || type === "1") {
      ol.classList.add('collapsible');
      var summary = document.createElement('summary');
      var details = document.createElement('details');
      details.appendChild(summary);
      details.appendChild(ol);

      return details;
    } else {
      return ol;
    }
  } else {
    return null;  
  }
}

document.getElementById('listContainer').addEventListener('click', function (event) {
  const clickedElement = event.target;
  if (clickedElement.tagName === 'BUTTON' && clickedElement.textContent === '⋫ ') {
    const liToRemove = clickedElement.parentNode;
    liToRemove.parentNode.removeChild(liToRemove);  
  updateFooter();
  }
});
function removeElement(keyToRemove) {
  delete dict[keyToRemove];
  buildHierarchy('');
}

listContainer.appendChild(buildHierarchy(''));

listContainer.addEventListener('click', function (event) {
    const clickedElement = event.target;
    const description = getDescription(clickedElement.textContent);
    const itemName = clickedElement.textContent.trim();
    const imageSource = dict[itemName][1];
    displayDescription(description, itemName, imageSource);
  });
  listContainer.addEventListener('dblclick', function (event) {
    const clickedElement = event.target;
      const itemName = clickedElement.textContent.trim();
  
      // Get the current values from the dict object
      const [parent, imageUrl, description] = dict[itemName];
  
      // Display current values in an alert and prompt for new values
      const newImageUrl = prompt(`Current Image URL: ${imageUrl}\nEnter new Image URL:`, imageUrl);
      const newDescription = prompt(`Current Description: ${description}\nEnter new Description:`, description);
  
      // Update the dict object with the new values
      dict[itemName] = [parent, newImageUrl, newDescription];
  
      // Rebuild the hierarchy to reflect the changes
      listContainer.innerHTML = '';
      listContainer.appendChild(buildHierarchy(''));
    
  });
  
  function getDescription(item) {
    return dict[item][2];
  }
  
  function displayDescription(description, itemName, imageSource) {
    const descriptionElement = document.querySelector('.frame2 .desc');
    const itemNameElement = document.querySelector('.frame2 .mot h1');
    const imageElement = document.querySelector('.frame2 .img');
    
    if (imageSource.trim() !== "") {
        imageElement.innerHTML = '';
        const newImage = new Image();
        newImage.src = imageSource;
        newImage.alt = itemName;
        imageElement.appendChild(newImage);
        descriptionElement.innerHTML = description;
        itemNameElement.innerHTML = itemName;
    } else {
        imageElement.innerHTML = 'Aucune image';
        descriptionElement.innerHTML = description;
        itemNameElement.innerText = itemName;
    }
}

// collapsable problem doesn't inherit
function addNewItem(key, choice) {
  const newItemKey = prompt('Enter the key for the new item:');
  const newItemImage = prompt('Enter the image link for the new item:');
  const newItemDescription = prompt('Enter the description for the new item:');


  const dictArray = Object.entries(dict);
  const selectedIndex = dictArray.findIndex(([k, v]) => k === key);
  if (choice === 1){
    dictArray.splice(selectedIndex, 0, [newItemKey, [dict[key][0], newItemImage, newItemDescription]]);
  }
  else
  {
    dictArray.splice(selectedIndex + 1, 0, [newItemKey, [dict[key][0], newItemImage, newItemDescription]]);
  }
  dict = Object.fromEntries(dictArray);


  listContainer.innerHTML = '';
  updateFooter();
  listContainer.appendChild(buildHierarchy(''));
}

function updateFooter() {
  let level1Count = 0;
  let level2Count = 0;
  let level3Count = 0;

  Object.keys(dict).forEach((key) => {
    const parentKey = dict[key][0];

    if (!parentKey || !dict[parentKey]) {
      // Level 1 item not used just for the sake of my sanity
      level1Count++;
    } else if (dict[parentKey][0] in dict) {
      // Level 2 item not updating correctly needs fixes
      level2Count++;
    } else {
      // Level 3 item
      level3Count++;
    }
  });
  const averagemistersalta3 = level3Count / (level2Count || 1);
  const footer = document.querySelector('.footer');
  footer.innerHTML = `<h3>Nbr des mots:  ${level2Count}</h3><h3>Nbr des sous-cat ${level3Count}</h3><h3>Nbr des mots moyen par categorie:${averagemistersalta3.toFixed(0)}</h3>`;
}
updateFooter();
