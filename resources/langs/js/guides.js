document.addEventListener("DOMContentLoaded", function() { 
    var headers_sel = 'div#text-table-of-contents > ul:first-child > li > a';
    var headers = document.querySelectorAll(headers_sel);

    var subheaders_sel = 'div#text-table-of-contents > ul:first-child > li > ul';
    var subheaders = document.querySelectorAll(subheaders_sel);

    // Add toggler functions for all the main section links.
    // This implements an accordian style show / hide of for
    // the subsection links.
    for(var i=0; i < headers.length; i+=1) {
        headers[i].addEventListener('click', function() {
            for(var j=0; j < subheaders.length; j+=1) {
                if (subheaders[j].classList.length != 0) {
                    subheaders[j].classList.remove('show');
                }
            }

            var u = this.parentElement.querySelector('ul');
            if (u != null) {
                u.classList.toggle('show');
            }
        });
    }


    // Initialize the menu by showing the appropriate
    // subsections based on the hash in the url.

    var hash = location.hash;
    // Remove the "#".
    var title = hash.substr(1)

    if (title != "") {
        var elem = document.getElementById(title)
    }

    if (title == "" || elem == null) {
        section_num = 0;
    }
    else {
        section_num = parseInt(elem.firstChild.textContent[0]) - 1;
    }

    var par = headers[section_num].parentElement
    par.querySelector('ul').classList.toggle('show');

    // Recolor inline code blocks.
    var src = document.querySelector('.src');
    var cs = window.getComputedStyle(src);
    var bg = cs.getPropertyValue('background-color');
    var fc = cs.getPropertyValue('color');
    var codes = document.querySelectorAll('code')
    for(var i=0; i < codes.length; i += 1) {
        codes[i].style.backgroundColor = bg;
        codes[i].style.color = fc;
    }

    var menu = document.getElementById('mobile-menu');
    var toc  = document.getElementById('table-of-contents');
    menu.addEventListener('click', function() {
        toc.style.display = (toc.style.display == 'block') ? 'none' : 'block';
    });
});
