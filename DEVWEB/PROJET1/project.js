const listContainer = document.getElementById('listContainer');
alert("Double Click pour modifier")
//L9lib a3mo l9lib asidi, makhedamach 100% makatkhlikch tdir display les infos ATTENTION IMPORTANT!
function switcher() {
  const frame1 = document.querySelector('.frame1');
  const frame2 = document.querySelector('.frame2');
  frame1.classList.toggle('frame1');
  frame1.classList.toggle('frame2');
  frame2.classList.toggle('frame1');
  frame2.classList.toggle('frame2');
}
//Base données initial 
dict = {
  "Développement Web": [
      "",
      "",
      "Le développement Web désigne de manière générale les tâches associées au développement de sites Web destinés à être hébergés via un intranet ou Internet."
  ],
  "Côté client": [
      "Développement Web",
      "",
      "Fait référence à tout ce qui est affiché ou se déroule dans une application Web sur le client (appareil de l'utilisateur final). Cela inclut l'interface utilisateur, le design et l'expérience utilisateur."
  ],
  "Côté Serveur": [
      "Développement Web",
      "",
      "Fait référence à la logique et aux fonctionnalités qui s'exécutent côté serveur. Cela peut inclure la gestion des bases de données, le traitement des formulaires, et d'autres opérations qui ne sont pas directement visibles par l'utilisateur."
  ],
  "HTML": [
      "Côté client",
      "https://upload.wikimedia.org/wikipedia/commons/thumb/6/61/HTML5_logo_and_wordmark.svg/180px-HTML5_logo_and_wordmark.svg.png",
      "HyperText Markup Language: langage de balisage conçu pour représenter les pages web. HTML définit la structure de base d'une page web en utilisant des balises."
  ],
  "CSS": [
      "Côté client",
      "https://upload.wikimedia.org/wikipedia/commons/thumb/d5/CSS3_logo_and_wordmark.svg/800px-CSS3_logo_and_wordmark.svg.png",
      "Feuilles de style en cascade: est l'un des langages principaux du Web ouvert et a été standardisé par le W3C. CSS est utilisé pour styliser et mettre en forme les pages HTML, contrôlant l'aspect visuel et la mise en page."
  ],
  "JavaScript": [
      "Côté client",
      "https://upload.wikimedia.org/wikipedia/commons/6/6a/JavaScript-logo.png",
      "JavaScript est un langage de programmation côté client qui permet d'ajouter des fonctionnalités interactives aux pages web. Il est largement utilisé pour créer des effets dynamiques et améliorer l'expérience utilisateur."
  ],
  "PHP": [
      "Côté Serveur",
      "https://upload.wikimedia.org/wikipedia/commons/2/27/PHP-logo.svg",
      "Hypertext Preprocessor: langage de programmation libre, principalement utilisé pour produire des pages Web dynamiques via un serveur web. PHP est souvent intégré avec HTML pour créer des applications web dynamiques."
  ],
  "Python": [
      "Côté Serveur",
      "https://upload.wikimedia.org/wikipedia/commons/thumb/c/c3/Python-logo-notext.svg/600px-Python-logo-notext.svg.png",
      "Python est un langage de programmation polyvalent utilisé côté serveur pour le développement web. Il est apprécié pour sa lisibilité et sa facilité d'utilisation, ainsi que pour ses frameworks web populaires comme Django et Flask."
  ],
  "MySQL": [
      "Côté Serveur",
      "https://upload.wikimedia.org/wikipedia/fr/thumb/6/62/MySQL.svg/800px-MySQL.svg.png",
      "MySQL est un système de gestion de base de données relationnelle utilisé côté serveur. Il est souvent associé à PHP pour stocker et récupérer des données dans les applications web."
  ],
  "Bootstrap": [
      "Côté client",
      "https://upload.wikimedia.org/wikipedia/commons/thumb/b/b2/Bootstrap_logo.svg/800px-Bootstrap_logo.svg.png",
      "Bootstrap est un framework CSS et JavaScript open-source qui facilite le développement web en fournissant des composants réutilisables et une mise en page responsive."
  ]
}
function buildHierarchy(topParent, type) {
  var ol = document.createElement('ol');
  ol.type = type;
  Object.keys(dict).forEach(function (key) {
    if (dict[key][0] === topParent) {
      var li = document.createElement('li');
      //SummaryLi bach head element ol maykonch fih gher text, ykoun clickable
      var summaryLi = document.createElement('li');
      var summary = document.createElement('summary');
      summary.textContent = key;
      summaryLi.appendChild(summary);
      li.appendChild(summaryLi);

      const removeButton = document.createElement('button');
      removeButton.setAttribute('type', 'button');
      removeButton.addEventListener('click', function () {
        //so that all the children get deleted too
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
     addblButton.addEventListener('click', function ()
     {
      let choice=2;
      addNewItem(key, choice);
  });
     addblButton.textContent = '⊶';
     li.appendChild(addblButton);
      ol.appendChild(li);
      
      var children = buildHierarchy(key, "1");
      if (children)
      {
        li.appendChild(children);
      }
      else
      {
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
}

listContainer.appendChild(buildHierarchy(''));
//mochkil machi hna, alert test khedam mli kandiro click
listContainer.addEventListener('click', function clicky(event) {
    const clickedElement = event.target;
    const description = getDescription(clickedElement.textContent);
    const itemName = clickedElement.textContent.trim();
    const imageSource = dict[itemName][1];
    displayDescription(description, itemName, imageSource);
  });

listContainer.addEventListener('dblclick', function (event) {
    const clickedElement = event.target;
      const itemName = clickedElement.textContent.trim();
  
      const [parent, imageUrl, description] = dict[itemName];
  //hayedt itemname bach matrewnach 9adiya mafhmetch ndir lih update mora kola changement
      const newImageUrl = prompt(`Image URL actuel: ${imageUrl}\nSaisir le nouvel URL:`, imageUrl);
      const newDescription = prompt(`Description actuel: ${description}\nSaisir la nouvelle Description:`, description);
      if (newDescription)
     { 
      dict[itemName] = [parent, newImageUrl, newDescription];
  
      // Rebuild the hierarchy 
      listContainer.innerHTML = '';
      listContainer.appendChild(buildHierarchy(''));
     }
     else
     {
      alert("Qq chose a mal passer, aucun changement n'est affecter au element")
     }
  });
  
  function getDescription(item) {
    return dict[item][2];
  }
  
  function displayDescription(description, itemName, imageSource) {
    //ha lmochkil finahowa, null gets stored mli kandiro click whna 9albin les frames
    const descriptionElement = document.querySelector('.frame2 .desc');
    const itemNameElement = document.querySelector('.frame2 .headline h1');
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
  const newItemKey = prompt('Saisir le nom de nouvel element du dictionnaire:');
  const newItemImage = prompt('Saisir URL l\'image (Laisse vide si n\'existe pas):');
  const newItemDescription = prompt('Saisir la description du nouvel element:');
  

  const dictArray = Object.entries(dict);
  const selectedIndex = dictArray.findIndex(([k, v]) => k === key);
  if (newItemKey && newItemDescription)
  {
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
  alert(`Nouvel item ${newItemKey} cree avec succee!`)
  }
  else
  {
    alert("Qq chose a mal passer, refaire l'addition de nouvel element SVP")
  }
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
      level2Count++;
    } else {
      level3Count++;
    }
  });
  const averagemistersalta3 = level2Count / (level3Count || 1);
  const footer = document.querySelector('.footer');
  //Removed numbers after the comma
  footer.innerHTML = `<h3>Nbr des mots:  ${level2Count}</h3><h3>Nbr des sous-cat ${level3Count}</h3><h3>Nbr des mots moyen par categorie:${averagemistersalta3.toFixed(0)}</h3>`;
}
updateFooter();