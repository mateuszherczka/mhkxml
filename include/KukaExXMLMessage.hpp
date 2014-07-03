#ifndef KUKAEXXMLMESSAGE_H
#define KUKAEXXMLMESSAGE_H

#include <iostream>
#include <fstream>
#include <string>

#include <tinyxml2.h>

using namespace std;
using namespace tinyxml2;

/**
    Holds an xml structure similar to
    kuka krlxml demo app.
    Uses tinyXml2.
*/

class KukaExXMLMessage
{
    public:
        KukaExXMLMessage() {}
        virtual ~KukaExXMLMessage() {}

    protected:

    private:

    XMLDocument doc;    // created here

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
        xpos_text = doc.NewText("300.0");   // can we pass doubles instead?
        ypos_text = doc.NewText("0.0");
        zpos_text = doc.NewText("300.0");
        external_data->InsertEndChild(position);
        position->InsertEndChild(xpos);
        xpos->InsertEndChild(xpos_text);
        position->InsertEndChild(ypos);
        ypos->InsertEndChild(ypos_text);
        position->InsertEndChild(zpos);
        zpos->InsertEndChild(zpos_text);


    }

};

#endif // KUKAEXXMLMESSAGE_H

/*

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
