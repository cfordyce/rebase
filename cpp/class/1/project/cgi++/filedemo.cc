#include "CGI.h"
#include "Escape.h"
#include "FileStream.h"

/* Ultra-short-n-simple demo of file upload */

int main() {
  CGI cgi ;

  cgi["file"] = new form_longfile() ;
  String Source("Source") ;
  cgi["display"] = new form_radio(Source, " ") ;
  cgi["display"]["source"] = "Source" ;
  cgi["display"]["render"] = "Rendered HTML" ;

  cgi.form() ;		// read the input!

/* Print a mini-form inviting user to upload a file */
  cout	<< "Content-type: text/html\n\n"
	"<title>CGI++ File Upload Demo</title>"
	"<h1>File Upload Demonstrator Program</h1>"

	"<p>Use the form to upload a file from your local system. "
	"When you upload an HTML file, you can either display source "
	"or render it (for other file types, the Display option has "
	"no effect).  Note that if you render an HTML file it is "
	"<em>not</em> parsed, so the file contents <em>should</em> "
	"be limited to body text or the results may be unpredictable. "
	"Do <b>not</b> send files containing confidential information!</p>"

	<< cgi.start("filedemo.cgi", "POST", "multipart/form-data")
	<< cgi.submit("Upload")
	<< cgi.render("file")
	<< " Display as: " << cgi.render("display")
	<< cgi.end() << "<hr>" ;

  if ( cgi.request_method() == "GET" )
    cout << "OK, waiting for you ..." ;

  else if ( !cgi.content_type().contains("multipart/form-data") )
    cout << "<p>Sorry, your Browser doesn't support HTTP File Upload.</p>" ;

  else if ( ! cgi["file"] )
    cout << "Didn't get anything - please try again." ;

  else {
    cout << "<h2>Upload of " << cgi["file"].filename() << "</h2>"
	 << "<h3>Headers</h3>" ;

    Map& headers (cgi["file"].headers()) ;
    for (Pix x = headers.first(); x; headers.next(x))
	cout << headers.key(x) << ": " << headers.contents(x) << "<br>";

    cout << "<h3>Body</h3><br>" ;
    String ctype("Content-Type") ;
    ctype = headers[ctype] ;
    ctype.downcase() ;
    if ( ctype.contains("text/html")
	&& ( cgi["display"].as_text() == "render" ) )
      cout << cgi["file"].as_longtext() ;
    else if ( ( ctype == NULL_String ) || ctype.contains("text") )
      cout << "<pre>" << html_escape(cgi["file"].as_longtext()) << "</pre>" ;
    else {
      cout << "<p>Non-text file not displayed in HTML page." ;
    }
  }

  cout	<< "<hr><p align=right>"
	"<a href=\"filedemo.cc\">The C++ source for this "
	"demo program is here.</a></p><hr>" ;

  return 0 ;
}
