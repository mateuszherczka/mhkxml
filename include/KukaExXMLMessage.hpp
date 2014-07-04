#ifndef KUKAEXXMLMESSAGE_H
#define KUKAEXXMLMESSAGE_H

#include <iostream>
#include <fstream>
#include <string>

#include <tinyxml2.h>

using namespace std;
using namespace tinyxml2;

// DONE: compare delimiters in tinyXml and kuka files.
// Difference in whitespaces! We will see if this is a problem.
// DONE: write program that prints all chars in xml char array

// TODO: (maybe not needed) implement *clean* double to string conversion
// TODO: XML Parsing of kuka message
// TODO: Test XML sending with echoserver

// DONE: hardcode outgoing xml with just c++
// Implemented several methods

/**
Holds an xml structure similar to
kuka krlxml demo app.
Uses tinyXml2.
*/

class KukaExXMLMessage
{
    public:

    KukaExXMLMessage() : doc(true,PRESERVE_WHITESPACE) {
        if(doc.WhitespaceMode() == COLLAPSE_WHITESPACE) {
            cout << "Collapsing whitespace." << endl;
        }
        else {
            cout << "Preserving whitespace." << endl;
        }

        outDataBuffer = new char[BUFFER_SIZE];

        buildKukaExDocumentTXML2();
    }


    virtual ~KukaExXMLMessage() {
        // TODO: write destructor
        delete outDataBuffer;
    }

    void toFile(const char *filename) {

        ofstream myfile (filename);
        if (myfile.is_open())
        {
            myfile << outDataBuffer;
            myfile.close();
        }
        else cout << "Unable to open file";
//        XMLError toFileStatus = doc.SaveFile(filename, false);

//        FILE *fp = fopen(filename,"w");
//        if (fp == NULL) {cout << "Error opening file";}
//
//        XMLPrinter filePrinter(fp);
//        doc.Print(&filePrinter);
//        fclose(fp);

        // cout << "Tried saving xml file: " << toFileStatus << endl;  // debug msg
    }

    void printAllAsciiFromTwoFiles(const char *filenameA, const char *filenameB) {

        ifstream finA;
        ifstream finB;

        finA.open(filenameA, ios::in);
        finB.open(filenameB, ios::in);

        char charA;
        char charB;

        char *charADesc = "AAAAA";
        char *charBDesc = "BBBBB";

        int diff = 0;

        cout << "Ascii in files " << filenameA << " and " << filenameB << " and diff so far:" << endl;

        // we use file A as sync reference
        while (!finA.eof()) {

            finA.get(charA);
            finB.get(charB);

            int asciiA = int(charA);
            int asciiB = int(charB);

            if (asciiA != asciiB) {
                ++diff;
            }

            if (asciiA == 10) {
                charADesc = "LF";
            }
            else if (asciiA == 13) {
                charADesc = "CR";
            }
            else if (asciiA == 9) {
                charADesc = "TAB";
            }
            else if (asciiA == 32) {
                charADesc = "SPACE";
            }
            else {
                //sprintf(charADesc,"%c",asciiA);
                charADesc = "-";
            }

            if (asciiB == 10) {
                charBDesc = "LF";
            }
            else if (asciiB == 13) {
                charBDesc = "CR";
            }
            else if (asciiB == 9) {
                charBDesc = "TAB";
            }
            else if (asciiB == 32) {
                charBDesc = "SPACE";
            }
            else {
                //sprintf(charADesc,"%c",asciiB);
                charBDesc = "-";
            }

            cout << asciiA << " " << charADesc << " " << asciiB << " " << charBDesc << " " << diff << endl;

        }

        cout << endl;
    }

    void printAllAsciiFromFile(const char *filename) {

        ifstream fin;
        fin.open(filename, ios::in);

        char achar;

        cout << "All ascii in file: " << filename << endl;

        while (!fin.eof()) {

            fin.get(achar);
            int ascii = int(achar);

            cout << ascii << " " << achar << endl;

        }

        cout << endl;
    }

    void printAllCharsFromFile(const char *filename) {

        ifstream fin;
        fin.open(filename, ios::in);

        char achar;

        cout << "All characters in file: " << filename << endl;

        while (!fin.eof()) {

            fin.get(achar);
            //int ascii = int(achar);

            cout << achar;

        }

        cout << endl;
    }

    void printSpfXml() {
        cout << "Building with no tabs." << endl;
        buildKukaExDocumentSpfTab();
        toFile("spf_xml_tabs.xml");
        cout << "With Tabs Buffersize:" << outDataBufferLength << endl;
        cout << outDataBuffer;

        cout << "Building with tabs." << endl;
        buildKukaExDocumentSpfNoTab();
        toFile("spf_xml_notabs.xml");
        cout << "No Tabs Buffersize:" << outDataBufferLength << endl;
        cout << outDataBuffer;
    }

    void setPosXYZ(double x, double y, double z) {
        xpos = x;
        ypos = y;
        zpos = z;
    }

    protected:

    private:

    const int TAB = 9;
    const int LF = 10;
    const int CR = 13;
    const int BR = LF;

    const int BUFFER_SIZE = 10240;

    char *outDataBuffer;
    int outDataBufferLength = 0;

    XMLDocument doc;

    char *estr = "EKX message example!";

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

    /**
    Build an xml document with tinyxml2 exactly like kuka example,
    so we can compare char for char if they are identical.
    (Testing shows they are not identical, whitespaces are different).
    The actual data is bogus and should be updated to
    proper values before use!
    */
    void buildKukaExDocumentTXML2() {

        XMLElement  *external_data; // root

        XMLElement  *tstring;
        XMLText     *tstring_text;

        XMLElement  *position;
        XMLElement  *xpos;
        XMLText     *xpos_text;
        XMLElement  *ypos;
        XMLText     *ypos_text;
        XMLElement  *zpos;
        XMLText     *zpos_text;

        XMLElement  *temperature;
        XMLText     *temperature_text;
        XMLElement  *cpu;
        XMLText     *cpu_text;
        XMLElement  *fan;
        XMLText     *fan_text;

        XMLElement  *ints;
        XMLElement  *astate;
        XMLText     *astate_text;
        XMLElement  *bstate;
        XMLText     *bstate_text;

        XMLElement  *boolean;
        XMLElement  *cstate;
        XMLText     *cstate_text;

        XMLElement  *frames_1;  // frames hold values in attributes
        XMLElement  *xframe_1;

        XMLElement  *frames_2;
        XMLElement  *xframe_2;

        XMLElement  *frames_3;
        XMLElement  *xframe_3;

        external_data = doc.NewElement("ExternalData");
        doc.InsertEndChild(external_data);

        tstring = doc.NewElement("TString");
        tstring_text = doc.NewText("EKX message example!");
        external_data->InsertEndChild(tstring);
        tstring->InsertEndChild(tstring_text);

        position = doc.NewElement("Position");
        xpos = doc.NewElement("XPos");
        ypos = doc.NewElement("YPos");
        zpos = doc.NewElement("ZPos");
        xpos_text = doc.NewText("1523.232");
        ypos_text = doc.NewText("494.2343");
        zpos_text = doc.NewText("14.4");
        external_data->InsertEndChild(position);
        position->InsertEndChild(xpos);
        xpos->InsertEndChild(xpos_text);
        position->InsertEndChild(ypos);
        ypos->InsertEndChild(ypos_text);
        position->InsertEndChild(zpos);
        zpos->InsertEndChild(zpos_text);

        temperature = doc.NewElement("Temperature");
        cpu = doc.NewElement("Cpu");
        cpu_text = doc.NewText("35.09787");
        fan = doc.NewElement("Fan");
        fan_text = doc.NewText("40.75869");
        external_data->InsertEndChild(temperature);
        temperature->InsertEndChild(cpu);
        cpu->InsertEndChild(cpu_text);
        temperature->InsertEndChild(fan);
        fan->InsertEndChild(fan_text);

        ints = doc.NewElement("Ints");
        astate = doc.NewElement("AState");
        bstate = doc.NewElement("BState");
        astate_text = doc.NewText("23456");
        bstate_text = doc.NewText("64");
        external_data->InsertEndChild(ints);
        ints->InsertEndChild(astate);
        astate->InsertEndChild(astate_text);
        ints->InsertEndChild(bstate);
        bstate->InsertEndChild(bstate_text);

        boolean = doc.NewElement("Boolean");
        cstate = doc.NewElement("CState");
        cstate_text = doc.NewText("0");
        external_data->InsertEndChild(boolean);
        boolean->InsertEndChild(cstate);

        frames_1 = doc.NewElement("Frames");
        xframe_1 = doc.NewElement("XFrame");
        external_data->InsertEndChild(frames_1);
        frames_1->InsertEndChild(xframe_1);
        xframe_1->SetAttribute("XPos","1.6");
        xframe_1->SetAttribute("YPos","2.5");
        xframe_1->SetAttribute("ZPos","3.4");
        xframe_1->SetAttribute("ARot","4.3");
        xframe_1->SetAttribute("BRot","5.2");
        xframe_1->SetAttribute("CRot","6.1");

        frames_2 = doc.NewElement("Frames");
        xframe_2 = doc.NewElement("XFrame");
        external_data->InsertEndChild(frames_2);
        frames_2->InsertEndChild(xframe_2);
        xframe_2->SetAttribute("XPos","13.1");
        xframe_2->SetAttribute("YPos","24.5");
        xframe_2->SetAttribute("ZPos","837.54");
        xframe_2->SetAttribute("ARot","142.3");
        xframe_2->SetAttribute("BRot","65.2");
        xframe_2->SetAttribute("CRot","56.94");

        frames_3 = doc.NewElement("Frames");
        xframe_3 = doc.NewElement("XFrame");
        external_data->InsertEndChild(frames_3);
        frames_3->InsertEndChild(xframe_3);
        xframe_3->SetAttribute("XPos","764.6");
        xframe_3->SetAttribute("YPos","134.5");
        xframe_3->SetAttribute("ZPos","36.54");
        xframe_3->SetAttribute("ARot","24.3");
        xframe_3->SetAttribute("BRot","36.2");
        xframe_3->SetAttribute("CRot","5");
    }

    void buildKukaExDocumentSpfTab() {

        const char* exampleXMLFormat =
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

        outDataBufferLength = sprintf(outDataBuffer,exampleXMLFormat,
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

    void buildKukaExDocumentSpfNoTab() {

        // this has to be non-indented in this silly way
        // unless we want the extra tabs...
        // better solution?
        const char* exampleXMLFormat =
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

        outDataBufferLength = sprintf(outDataBuffer,exampleXMLFormat,

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

};

#endif // KUKAEXXMLMESSAGE_H

/*

// the kuka example xml

<ExternalData>
    <TString>EKX message example!</TString>
    <Position>
        <XPos>1523.232</XPos>
        <YPos>494.2343</YPos>
        <ZPos>14.4</ZPos>
    </Position>
    <Temperature>
        <Cpu>35.09787</Cpu>
        <Fan>40.75869</Fan>
    </Temperature>
    <Ints>
        <AState>23456</AState>
        <BState>64</BState>
    </Ints>
    <Boolean>
        <CState>0</CState>
    </Boolean>
    <Frames>
        <XFrame XPos="1.6" YPos="2.5" ZPos="3.4" ARot="4.3" BRot="5.2" CRot="6.1" />
    </Frames>
    <Frames>
        <XFrame XPos="13.1" YPos="24.5" ZPos="837.54" ARot="142.3" BRot="65.2" CRot="56.94" />
    </Frames>
    <Frames>
        <XFrame XPos="764.6" YPos="134.5" ZPos="36.54" ARot="24.3" BRot="36.2" CRot="5" />
    </Frames>
</ExternalData>

*/
