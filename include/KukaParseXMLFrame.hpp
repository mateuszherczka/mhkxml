#ifndef KUKAPARSEXMLFRAME_H
#define KUKAPARSEXMLFRAME_H


class KukaParseXMLFrame
{
    public:
        const int MALFORMED_XML_ERROR = 1;

        KukaParseXMLFrame() {}
        virtual ~KukaParseXMLFrame() {

            // TODO: destructor
        }

        bool parse(boost::asio::streambuf &message) {
            parse(streambufToPtr(message));
        }

        bool parse(const char* buffer) {

            doc.Parse(buffer);
            XMLHandle docHandle( &doc );

            xml_error_state = doc.ErrorID();
            if ( xml_error_state != 0 ) {
                XMLError("Buffer could't be parsed");
                cout << "ErrorID: " << xml_error_state << endl;
                return false;
            }


            frame = docHandle.FirstChildElement( "Rob" ).
                        FirstChildElement( "Frame" ).
                        ToElement();

            if ( frame ) {    // check for nulpointer

                int xmlerr = 0;

                xmlerr += frame->QueryDoubleAttribute( "XPos",&xPos );    // errorcode 0 if ok

                xmlerr += frame->QueryDoubleAttribute( "YPos",&yPos );

                xmlerr += frame->QueryDoubleAttribute( "ZPos",&zPos );

                xmlerr += frame->QueryDoubleAttribute( "ARot",&aRot );    // errorcode 0 if ok

                xmlerr += frame->QueryDoubleAttribute( "BRot",&bRot );

                xmlerr += frame->QueryDoubleAttribute( "CRot",&cRot );

                if (xmlerr != 0) { XMLError("Frame Attributes"); }
            }
            else {  // something wrong with xml
                XMLError("Frame");
                return false;
            }
        }

        const char * streambufToPtr(boost::asio::streambuf &message) {
            boost::asio::streambuf::const_buffers_type bufs = message.data();
            std::string astr(boost::asio::buffers_begin(bufs), boost::asio::buffers_begin(bufs) + message.size());
            return astr.c_str();
            //return astr;
        }

        void printValues() {

            cout << xPos << endl;
            cout << yPos << endl;
            cout << zPos << endl;
            cout << aRot << endl;
            cout << bRot << endl;
            cout << cRot << endl;

        }

    protected:
    private:

    //int error_state = 0;
    int xml_error_state = 0;
    XMLDocument doc;

    double xPos;
    double yPos;
    double zPos;

    double aRot;
    double bRot;
    double cRot;

    XMLElement *frame;

    void XMLError(const char *e) {
        cout << "XML malformed at " << e << " !" << endl;
        xml_error_state = MALFORMED_XML_ERROR;
    }

};

#endif // KUKAPARSEXMLFRAME_H
