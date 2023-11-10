const listContainer = document.getElementById('listContainer');

// Dictionary of items
const dict = {
  "HTML": ["Côté client", "https://upload.wikimedia.org/wikipedia/commons/thumb/6/61/HTML5_logo_and_wordmark.svg/800px-HTML5_logo_and_wordmark.svg.png", "HyperText Markup Language: langage de balisage conçu pour représenter les pages web."],
  "CSS": ["Côté client", "https://upload.wikimedia.org/wikipedia/commons/thumb/d/d5/CSS3_logo_and_wordmark.svg/640px-CSS3_logo_and_wordmark.svg.png", "Feuilles de style en cascade: est l'un des langages principaux du Web ouvert et a été standardisé par le W3C"],
  "PHP": ["Côté Serveur", "", "Hypertext Preprocessor: langage de programmation libre, principalement utilisé pour produire des pages Web dynamiques via un serveur web."],
  "Côté client": ["Développement Web", "", "fait référence à tout ce qui est affiché ou se déroule dans une application Web sur le client (appareil de l'utilisateur final)"],
  "Développement Web": ["", "", "Le développement Web désigne de manière générale les tâches associées au développement de sites Web destinés à être hébergés via un intranet ou Internet."],
  "Côté Serveur": ["Développement Web", "", "Description for Côté Serveur"],
  "oppa": ["", "", "Le développement Web désigne de manière générale les tâches associées au développement de sites Web destinés à être hébergés via un intranet ou Internet."],
  "Côté": ["oppa", "", "Description for Côté Serveur"],
  "PP": ["Côté", "php.jpg", "Hypertext Preprocessor: langage de programmation libre, principalement utilisé pour produire des pages Web dynamiques via un serveur web."]
};

function buildHierarchy(topParent, type) {
    var ol = document.createElement('ol');
    ol.type = type;
  
    Object.keys(dict).forEach(function (key) {
      if (dict[key][0] === topParent) {
        var li = document.createElement('li');
        li.textContent = key;
        var children = buildHierarchy(key, "1");
        if (children) {
          li.appendChild(children);
        }
  
        ol.appendChild(li);
      }
    });
  
    if (ol.childNodes.length > 0) {
      // Check if it's the first level or second level
      if (type === "I" || type === "1") {
        // Add a class to the ol for styling purposes
        ol.classList.add('collapsible');
        // Add summary and details elements
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
  

// Append the hierarchy to the listContainer
listContainer.appendChild(buildHierarchy(''));





// Add an event listener to the listContainer element to detect when anything is clicked
listContainer.addEventListener('click', function (event) {
    // Get the clicked element
    const clickedElement = event.target;
  
    // Get the description of the clicked element
    const description = getDescription(clickedElement.textContent);
    const itemName = clickedElement.textContent.trim();
    const imageSource = dict[itemName][1];
    // Display the description and item name in the frame2 div
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
        // If imageSource is not empty, update the image
        imageElement.innerHTML = '';  // Clear existing content in the imageElement

        // Create a new Image element
        const newImage = new Image();
        newImage.src = imageSource;
        newImage.alt = itemName;  // Set alt attribute for accessibility

        // Append the new Image to the imageElement
        imageElement.appendChild(newImage);

        // Set other content
        descriptionElement.innerHTML = description;
        itemNameElement.innerHTML = itemName;
    } else {
        // If imageSource is empty, update text content only
        imageElement.innerHTML = 'Aucune image';
        descriptionElement.innerHTML = description;
        itemNameElement.innerText = itemName;
    }
}
  