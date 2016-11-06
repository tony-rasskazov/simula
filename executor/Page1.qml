import QtQuick 2.7

import com.unet.distributedcommunications 1.0

Page1Form {
    id: pageForm1

    spinBox1.value: ExecutorAPI.intValue
    spinBox2.value: ExecutorAPI.intValue
    textInput1.text: ExecutorAPI.stringValue
    switch1.checked: ExecutorAPI.boolValue
    slider1.value: ExecutorAPI.realValue

    button1.onClicked: {
        ExecutorAPI.stringValue = textInput1.text;
    }

    button2.onClicked: {
        var val = ExecutorAPI.doSomething(++ExecutorAPI.intValue);
        console.log("Button 2 clicked. val=" + val);
    }

    slider1.onValueChanged: {
        ExecutorAPI.realValue = slider1.value;
    }

    spinBox1.onValueChanged: {
        ExecutorAPI.intValue = spinBox1.value;
    }

    switch1.onCheckedChanged: {
        ExecutorAPI.boolValue = switch1.checked;
    }
}
