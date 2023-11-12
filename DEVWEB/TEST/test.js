function fctlst() {
    // Accèder aux éléments
    var list = document.getElementById('list');
    var txt = document.getElementById("txt");
    var ele = document.getElementsByName('choix');
    var li = document.createElement('li');
    var texteNode = document.createTextNode(""+txt.value);
    li.appendChild(texteNode);

    // Créer et ajouter les boutons "Modifier" et "Supprimer"
    var btnupdate = document.createElement("input");
    btnupdate.setAttribute("type","button");
    btnupdate.setAttribute("onclick","update(this)");
    btnupdate.value = "Modifier";
    li.appendChild(btnupdate);

    var btndelete = document.createElement("input");
    btndelete.setAttribute("type","button");
    btndelete.setAttribute("onclick","remove(this)");
    btndelete.value = "Supprimer";
    li.appendChild(btndelete);

    if(ele[0].checked)
    list.insertBefore(li, list.firstChild);
    else
    list.appendChild(li);
    txt.value = '';
}



