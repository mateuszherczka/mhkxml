#ifndef KUKABUILDXMLEXAMPLE_H
#define KUKABUILDXMLEXAMPLE_H


class KukaBuildXMLExample
{
    public:
        KukaBuildXMLExample() {}
        virtual ~KukaBuildXMLExample() {}

        /*
        Fills streambuf.
        */
        void build( boost::asio::streambuf &message ) {

            std::ostream to_message_stream(&message);

            to_message_stream   << "<ExternalData>\r\n";
            to_message_stream   << "<TString>" << estr << "</TString>\r\n";
            to_message_stream   << "<Position>\r\n";
            to_message_stream   << "<XPos>" << xpos << "</XPos>\r\n";
            to_message_stream   << "<YPos>" << ypos << "</YPos>\r\n";
            to_message_stream   << "<ZPos>" << zpos << "</ZPos>\r\n";
            to_message_stream   << "</Position>\r\n";
            to_message_stream   << "<Temperature>\r\n";
            to_message_stream   << "<Cpu>" << cpu << "</Cpu>\r\n";
            to_message_stream   << "<Fan>" << fan << "</Fan>\r\n";
            to_message_stream   << "</Temperature>\r\n";
            to_message_stream   << "<Ints>\r\n";
            to_message_stream   << "<AState>" << astate << "</AState>\r\n";
            to_message_stream   << "<BState>" << bstate << "</BState>\r\n";
            to_message_stream   << "</Ints>\r\n";
            to_message_stream   << "<Boolean>\r\n";
            to_message_stream   << "<CState>" << cstate << "</CState>\r\n";
            to_message_stream   << "</Boolean>\r\n";
            to_message_stream   << "<Frames>\r\n";
            to_message_stream   << "<XFrame XPos=\"" << f1xpos << "\" "
                                << "YPos=\"" << f1ypos << "\" "
                                << "ZPos=\"" << f1zpos << "\" "
                                << "ARot=\"" << f1arot << "\" "
                                << "BRot=\"" << f1brot << "\" "
                                << "CRot=\"" << f1crot << "\"/>\r\n";
            to_message_stream   << "</Frames>\r\n";
            to_message_stream   << "<Frames>\r\n";
            to_message_stream   << "<XFrame XPos=\"" << f2xpos << "\" "
                                << "YPos=\"" << f2ypos << "\" "
                                << "ZPos=\"" << f2zpos << "\" "
                                << "ARot=\"" << f2arot << "\" "
                                << "BRot=\"" << f2brot << "\" "
                                << "CRot=\"" << f2crot << "\"/>\r\n";
            to_message_stream   << "<Frames>\r\n";
            to_message_stream   << "</Frames>\r\n";
            to_message_stream   << "<XFrame XPos=\"" << f3xpos << "\" "
                                << "YPos=\"" << f3ypos << "\" "
                                << "ZPos=\"" << f3zpos << "\" "
                                << "ARot=\"" << f3arot << "\" "
                                << "BRot=\"" << f3brot << "\" "
                                << "CRot=\"" << f3crot << "\"/>\r\n";
            to_message_stream   << "</Frames>\r\n";
            to_message_stream   << "</ExternalData>\r\n";
            //to_message_stream   << "\r\n";
        }

        /*
        Just to change something.
        */
        void setPosXYZ(double x, double y, double z) {
            xpos = x;
            ypos = y;
            zpos = z;
        }
        /*
        void buildKukaExDocumentTab(const char *buffer) {

            outDataBufferLength = sprintf(buffer,exampleXMLFormatTab,
                LF,
                TAB,estr,LF,
                TAB,BR,
                TAB,TAB,xpos,BR,
                TAB,TAB,ypos,BR,
                TAB,TAB,zpos,BR,
                TAB,BR,
                TAB,BR,
                TAB,TAB,cpu,BR,
                TAB,TAB,fan,BR,
                TAB,BR,
                TAB,BR,
                TAB,TAB,astate,BR,
                TAB,TAB,bstate,BR,
                TAB,BR,
                TAB,BR,
                TAB,TAB,cstate,BR,
                TAB,BR,
                TAB,BR,
                TAB,TAB,f1xpos,f1ypos,f1zpos,f1arot,f1brot,f1crot,BR,
                TAB,BR,
                TAB,BR,
                TAB,TAB,f2xpos,f2ypos,f2zpos,f2arot,f2brot,f2crot,BR,
                TAB,BR,
                TAB,BR,
                TAB,TAB,f3xpos,f3ypos,f3zpos,f3arot,f3brot,f3crot,BR,
                TAB,BR,
                BR
                );
        }

        void buildKukaExDocumentNoTab(const char *buffer) {

            outDataBufferLength = sprintf(buffer,exampleXMLFormatNoTab,

                estr,
                xpos,
                ypos,
                zpos,
                cpu,
                fan,
                astate,
                bstate,
                cstate,
                f1xpos,f1ypos,f1zpos,f1arot,f1brot,f1crot,
                f2xpos,f2ypos,f2zpos,f2arot,f2brot,f2crot,
                f3xpos,f3ypos,f3zpos,f3arot,f3brot,f3crot

                );
        }
    */
    protected:
    private:

        const int TAB = 9;
        const int LF = 10;
        const int CR = 13;
        const int BR = LF;

        int outDataBufferLength = 0;

        XMLDocument doc;

        const char *estr = "EKX message example!";

        double xpos = 1523.232;
        double ypos = 494.2343;
        double zpos = 14.4;

        double cpu = 35.09787;
        double fan = 40.75869;

        int astate = 23456;
        int bstate = 64;
        int cstate = 0;

        double f1xpos = 1.6;
        double f1ypos = 2.5;
        double f1zpos = 3.4;
        double f1arot = 4.3;
        double f1brot = 5.2;
        double f1crot = 6.2;

        double f2xpos = 13.1;
        double f2ypos = 24.5;
        double f2zpos = 837.54;
        double f2arot = 142.3;
        double f2brot = 65.2;
        double f2crot = 56.94;

        double f3xpos = 764.6;
        double f3ypos = 134.5;
        double f3zpos = 36.54;
        double f3arot = 24.3;
        double f3brot = 36.2;
        double f3crot = 5;

        const char* exampleXMLFormatTab =
"<ExternalData>%c\
%c<TString>%s</TString>%c\
%c<Position>%c\
%c%c<XPos>%g</XPos>%c\
%c%c<YPos>%g</YPos>%c\
%c%c<ZPos>%g</ZPos>%c\
%c</Position>%c\
%c<Temperature>%c\
%c%c<Cpu>%g</Cpu>%c\
%c%c<Fan>%g</Fan>%c\
%c</Temperature>%c\
%c<Ints>%c\
%c%c<AState>%d</AState>%c\
%c%c<BState>%d</BState>%c\
%c</Ints>%c\
%c<Boolean>%c\
%c%c<CState>%u</CState>%c\
%c</Boolean>%c\
%c<Frames>%c\
%c%c<XFrame XPos=\"%g\" YPos=\"%g\" ZPos=\"%g\" ARot=\"%g\" BRot=\"%g\" CRot=\"%g\" />%c\
%c</Frames>%c\
%c<Frames>%c\
%c%c<XFrame XPos=\"%g\" YPos=\"%g\" ZPos=\"%g\" ARot=\"%g\" BRot=\"%g\" CRot=\"%g\" />%c\
%c</Frames>%c\
%c<Frames>%c\
%c%c<XFrame XPos=\"%g\" YPos=\"%g\" ZPos=\"%g\" ARot=\"%g\" BRot=\"%g\" CRot=\"%g\" />%c\
%c</Frames>%c\
</ExternalData>%c\
";

        const char* exampleXMLFormatNoTab =
"<ExternalData> \n\
<TString>%s</TString> \n\
<Position> \n\
<XPos>%g</XPos> \n\
<YPos>%g</YPos> \n\
<ZPos>%g</ZPos> \n\
</Position> \n\
<Temperature> \n\
<Cpu>%g</Cpu> \n\
<Fan>%g</Fan> \n\
</Temperature> \n\
<Ints> \n\
<AState>%d</AState> \n\
<BState>%d</BState> \n\
</Ints> \n\
<Boolean> \n\
<CState>%u</CState> \n\
</Boolean> \n\
<Frames> \n\
<XFrame XPos=\"%g\" YPos=\"%g\" ZPos=\"%g\" ARot=\"%g\" BRot=\"%g\" CRot=\"%g\" /> \n\
</Frames> \n\
<Frames> \n\
<XFrame XPos=\"%g\" YPos=\"%g\" ZPos=\"%g\" ARot=\"%g\" BRot=\"%g\" CRot=\"%g\" /> \n\
</Frames> \n\
<Frames> \n\
<XFrame XPos=\"%g\" YPos=\"%g\" ZPos=\"%g\" ARot=\"%g\" BRot=\"%g\" CRot=\"%g\" /> \n\
</Frames> \n\
</ExternalData> \n\
";

};

#endif // KUKABUILDXMLEXAMPLE_H
