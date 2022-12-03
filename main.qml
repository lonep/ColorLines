import QtQuick 2.0
import QtQuick.Layouts
import QtQuick.Controls

import GameDesk 1.0

Window {
    id: window;

    minimumWidth: 360
    minimumHeight: 360
    visible: true
    title: qsTr("Color lines")

    ListModel {
    id: newModel
        ListElement {
            name: "Jim Williams"
            portrait: "pics/portrait.png"
        }
        ListElement {
            name: "John Brown"
            portrait: "pics/portrait.png"
        }
        ListElement {
            name: "Bill Smyth"
            portrait: "pics/portrait.png"
        }
        ListElement {
            name: "Sam Wise"
            portrait: "pics/portrait.png"
        }
    }

    ColumnLayout
    {
        FontLoader { id: resultFont; source: "qrc:/fonts/res/fonts/PressStart2P-Regular.ttf" }
        anchors.fill: parent;
        RowLayout
        {
            id: row;
            Layout.preferredWidth: window.width / 10;

            Button
            {
                Text {
                    id: newButtonLabel
                    anchors.horizontalCenter: parent.horizontalCenter
                    y: 10
                    text: "New"
                    font: resultFont.font
                    color: "white"
                    z: 2
                }

                font: resultFont.font


                Layout.fillWidth: true;


                Image {
                    id: newButton
                    anchors.fill: parent
                    source: parent.down ? "qrc:/icons/res/icons/Button_pressed.png" : "qrc:/icons/res/icons/Button.png"
                    z: 0

                }

                onPressed: {


                    newGame()

                }

                Layout.minimumHeight: 50
                Layout.minimumWidth: 50


                Layout.preferredHeight: parent.height / 7;
            }
            Rectangle
            {
                color: "black";
                Layout.fillWidth: true;

                Layout.minimumHeight: 50
                Layout.minimumWidth: 50


                Layout.preferredHeight: parent.height / 5;

                Text {
                    id: record
                    font: resultFont.font

                    anchors.fill: parent
                    text: qsTr("10")
                    color: "white"

                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter

                }

            }
            RowLayout
            {
                Layout.fillWidth: true;
                Layout.minimumHeight: 50
                Layout.minimumWidth: 50
                Layout.preferredHeight: parent.height / 5;

                Rectangle
                {
                    color: "red";
                    Layout.preferredHeight: parent.height / 3;
                    Layout.fillWidth: true;

                }

                Rectangle
                {
                    color: "green"
                    Layout.preferredHeight: parent.height / 3;
                    Layout.fillWidth: true;
                }

                Rectangle
                {
                    color: "blue"
                    Layout.preferredHeight: parent.height / 3;
                    Layout.fillWidth: true;

                }

            }
            Rectangle
            {
                color: "black";
                Layout.fillWidth: true;

                Layout.minimumHeight: 50
                Layout.minimumWidth: 50

                Layout.preferredHeight: parent.height / 5;

                Text {
                    id: result
                    font: resultFont.font

                    anchors.fill: parent
                    text: qsTr("10")
                    color: "white"

                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter

                }
            }
            Button
            {

                Text {
                    id: undoButtonLabel
                    anchors.horizontalCenter: parent.horizontalCenter
                    y: 10
                    text: "Undo"
                    font: resultFont.font
                    color: "white"
                    z: 2
                }

                font: resultFont.font


                Layout.fillWidth: true;


                Image {
                    id: undoButton
                    anchors.fill: parent
                    source: parent.down ? "qrc:/icons/res/icons/Button_pressed.png" : "qrc:/icons/res/icons/Button.png"
                    z: 0

                }

                onPressed: {
//                    undoButton.source = "qrc:/icons/res/icons/Button_pressed.png"
                    newGame()
                }

//                Layout.fillWidth: true;

                Layout.minimumHeight: 50
                Layout.minimumWidth: 50


                Layout.preferredHeight: parent.height / 7;
            }
        }




        GridView {
            Layout.fillHeight: true
            Layout.fillWidth: true
            cellHeight: height/9
            cellWidth: width/9

//            model: myModel
//            model: myModel
            model: GameDeskModel {}
            delegate: Rectangle {
//                required property string modelData
                border.color: "yellow"
                border.width: 1
                height: parent.height
                width: parent.width


                color: "black";


                Text {
                    anchors.fill: parent
                    text: model.ball
                    color: "red"
                }

                Text {
                    anchors.fill: parent
                    text:model.second
                    color: "pink"
                }
            }
        }




    }



    function newGame() {

    }

}
