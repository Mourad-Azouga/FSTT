const listContainer = document.getElementById('listContainer');
function toggleFrames() {
  const frame1 = document.querySelector('.frame1');
  const frame2 = document.querySelector('.frame2');
  const tempHTML = frame1.innerHTML;
  frame1.innerHTML = frame2.innerHTML;
  frame2.innerHTML = tempHTML;
}

const dict = {
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

	   const deleteButton = document.createElement('button');
     deleteButton.setAttribute('type', 'button');
     deleteButton.setAttribute('onclick', 'remove(this)');
     deleteButton.textContent = '⋫ ';
     li.appendChild(deleteButton);

     var addabButton = document.createElement('button');
     addabButton.setAttribute('type', 'button');
     addabButton.addEventListener('click', function () {
       const clickedElement = addabButton.parentElement;
       const newListItem = document.createElement('li');
       const newSummary = document.createElement('summary');
       newSummary.textContent = 'New Item';
       newListItem.appendChild(newSummary);
       clickedElement.parentNode.insertBefore(newListItem, clickedElement);
     });
     addabButton.textContent = '⊷';
     li.appendChild(addabButton);
     
     
     var addblButton = document.createElement('button');
     addblButton.setAttribute('type', 'button');
     addblButton.addEventListener('click', function () {
             const clickedElement = addabButton.parentElement;
             const newListItem = document.createElement('li');
             const newSummary = document.createElement('summary');
             newSummary.textContent = 'New Item';
             newListItem.appendChild(newSummary);
             clickedElement.parentNode.insertBefore(newListItem, clickedElement.nextSibling);
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
  }
});


listContainer.appendChild(buildHierarchy(''));


listContainer.addEventListener('click', function (event) {
    const clickedElement = event.target;
    const description = getDescription(clickedElement.textContent);
    const itemName = clickedElement.textContent.trim();
    const imageSource = dict[itemName][1];
    displayDescription(description, itemName, imageSource);
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

