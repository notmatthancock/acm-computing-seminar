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
    if (par.querySelector('ul') != null) {
        par.querySelector('ul').classList.toggle('show');
    }

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


    // Menu open / close for mobile view.
    var open = document.getElementById('toc-open');
    var close= document.getElementById('toc-close');
    var toc  = document.getElementById('table-of-contents');
    var main = document.getElementById('main');
    open.addEventListener('click', function() {
        // Show the table of contents.
        toc.style.display = 'block';
        open.style.display = 'none';
        var w = window.getComputedStyle(toc).getPropertyValue('width');
        close.style.left = String(parseFloat(w) - 15)+"px";
        close.style.display = 'block';
    });
    close.addEventListener('click', function() {
        toc.style.display = 'none';
        close.style.display = 'none';
        open.style.display = 'block';
    });
});
