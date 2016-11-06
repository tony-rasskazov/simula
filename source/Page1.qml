import QtQuick 2.7

import com.unet.distributedcommunications 1.0

Page1Form {
    id: pageForm1

    spinBox1.value: SourceAPI.intValue
    spinBox2.value: SourceAPI.intValue

    button1.onClicked: {
        SourceAPI.stringValue = textInput1.text;
    }

    button2.onClicked: {
        var val = SourceAPI.doSomething(++SourceAPI.intValue);
        console.log("Button 2 clicked. val=" + val);
    }

    slider1.onValueChanged: {
        SourceAPI.realValue = slider1.value;
    }

    spinBox1.onValueChanged: {
        SourceAPI.intValue = spinBox1.value;
    }

    switch1.onCheckedChanged: {
        SourceAPI.boolValue = switch1.checked;
    }
}
