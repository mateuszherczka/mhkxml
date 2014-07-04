#ifndef KUKAPARSEXMLMESSAGE_H
#define KUKAPARSEXMLMESSAGE_H


#include <iostream>
#include <fstream>
#include <string>

#include <tinyxml2.h>

using namespace std;
using namespace tinyxml2;

class KukaParseXMLMessage
{
    public:
        KukaParseXMLMessage() {}
        virtual ~KukaParseXMLMessage() {}

    protected:
    private:

    XMLDocument doc;

    void loadAndParse(const char *filename) {
        doc.LoadFile( filename );
    }
};

#endif // KUKAPARSEXMLMESSAGE_H

/* ------ Example 2: Lookup information. ---- */
{
    XMLDocument doc;
    doc.LoadFile( "dream.xml" );

    // Structure of the XML file:
    // - Element "PLAY"      the root Element, which is the
    //                       FirstChildElement of the Document
    // - - Element "TITLE"   child of the root PLAY Element
    // - - - Text            child of the TITLE Element

    // Navigate to the title, using the convenience function,
    // with a dangerous lack of error checking.
    const char* title = doc.FirstChildElement( "PLAY" )->FirstChildElement( "TITLE" )->GetText();
    printf( "Name of play (1): %s\n", title );

    // Text is just another Node to TinyXML-2. The more
    // general way to get to the XMLText:
    XMLText* textNode = doc.FirstChildElement( "PLAY" )->FirstChildElement( "TITLE" )->FirstChild()->ToText();
    title = textNode->Value();
    printf( "Name of play (2): %s\n", title );
}
