#ifndef KUKAEXXMLMESSAGE_H
#define KUKAEXXMLMESSAGE_H

#include <iostream>
#include <fstream>
#include <string>

#include <tinyxml2.h>

using namespace std;
using namespace tinyxml2;

// TODO: compare delimiters in tinyXml and kuka files
// TODO: write program that prints all chars in xml char array
// TODO: implement *clean* double to string conversion

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

        buildDocument();
    }


    virtual ~KukaExXMLMessage() {
        // TODO: write destructor
    }

    void toFile(const char *filename) {
        //XMLError toFileStatus = doc.SaveFile(filename, false);

        FILE *fp = fopen(filename,"w");
        if (fp == NULL) {cout << "Error opening file";}

        XMLPrinter filePrinter(fp);
        doc.Print(&filePrinter);
        fclose(fp);

        // cout << "Tried saving xml file: " << toFileStatus << endl;  // debug msg
    }

    void printAllAsciiFromTwoFiles(const char *filenameA, const char *filenameB) {

        ifstream finA;
        ifstream finB;

        finA.open(filenameA, ios::in);
        finB.open(filenameB, ios::in);

        char charA;
        char charB;

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

            cout << asciiA << " " << asciiB << " " << diff << endl;

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

    protected:

    private:

    bool processEntities = true;

    XMLDocument doc;

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

    /**
    Build an xml document exactly like kuka example,
    so we can compare char for char if they are identical.
    The actual data is bogus and should be updated to
    proper values before use!
    */
    void buildDocument() {

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
