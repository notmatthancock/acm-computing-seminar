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

    // Show the submenu for the first header.
    headers[0].click()
});
