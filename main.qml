import QtQuick 2.0
import QtQuick.Layouts
import QtQuick.Controls

Window {
    id: window;

    minimumWidth: 360
    minimumHeight: 360
    visible: true
    title: qsTr("Color lines")


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
        Grid
        {
            columns: 9
            Layout.fillHeight: true;
            Layout.fillWidth: true;

            Repeater {
                anchors.fill: parent
                    model: 81
                    Rectangle {
                        width: parent.width / 9
                        height: parent.height / 9
                        border.width: 1
                        border.color: "white"
                        color: "grey"
                    }
            }
        }
    }



    function newGame() {

    }

}
