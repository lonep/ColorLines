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

    property bool choose: false
    property int lastColor: 0


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
                   gameLogic.newGame()
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
//            ListView //TODO шары следующего хода
//            {
//                id: nexBalls
//                orientation: ListView.Horizontal
//                Layout.fillWidth: true;
//                Layout.minimumHeight: 50
//                Layout.minimumWidth: 50
//                Layout.preferredHeight: parent.height / 5;

//                model: GameDeskModel {}
//                delegate : Item {

//                    id: nextBallItem
//                    height: nextBallItem / 3
//                    width:  nextBallItem / 3

////                    Image {
////                        id: nextCircle
////                        width: parent.width
////                        height: parent.height
////                        anchors.horizontalCenter: desk.horizontalCenter
////                        source: model.ball !== 0 ? "qrc:/icons/res/icons/circle_empty.png" : ""
////                        z: 2


////                    }

//                    Rectangle {
//                        id: nextCircleBackground
//                        width: 10
//                        height: 10
//                        anchors.fill: circle
//                        color: getColor(model.ball)
//                        radius: 50
//                        z: 1
//                    }
//                }

//            }
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

                Layout.minimumHeight: 50
                Layout.minimumWidth: 50


                Layout.preferredHeight: parent.height / 7;
            }
        }




        GridView {

            id: desk
            Layout.fillHeight: true
            interactive: false
            Layout.fillWidth: true
            cellHeight: height/9
            cellWidth: width/9

            model: GameDeskModel {}
            delegate: Rectangle {

                id: cell
                border.color: "white"
                border.width: 1
                height: parent.height
                width: parent.width

                color: "grey";
                Item {
                    id: area
                    width:  desk.cellHeight - 5
                    height: desk.cellHeight - 5
                    x:  (desk.cellWidth - width)/2
                    y:  (desk.cellHeight - height)/2

                    NumberAnimation on opacity {
                        id: escapeAnimation
                        to: 0
                        duration: 1000
                        running: false
                    }

                    Image {
                        id: circle
                        width: parent.width
                        height: parent.height

                        source: model.ball !== 0 ? "qrc:/icons/res/icons/circle_empty.png" : ""
                        z: 2


                    }

                    Rectangle {
                        id: circleBackground
                        width: circle.width - 30
                        height: circle.height - 30
                        anchors.fill: circle
                        color: getColor(model.ball)
                        radius: 50
                        z: 1
                    }

                    MouseArea {
                        width: circle.width - 30
                        height: circle.height - 30
                        anchors.fill: circle

                        onClicked: {
//                            escapeAnimation.start()
                                model.ball !== 0 ? chooseBall(model, circleBackground, circle) : setBall(model, circleBackground, circle, mouseX, mouseY)

                        }
                    }

                }

            }

            }

        }



    function checkValue(n)
    {
        console.log(n);
    }

    function startEscapeAnimation(item)
    {
        item.escapeAnimation.start()
    }

    function chooseBall(model, circleBackground, circle)
    {
        if(choose === false)
        {
            choose = true
            lastColor = model.ball
            model.ball = 0

            circleBackground.color = getColor(model.ball)
            circle.source = ""

        }

    }

    function setBall(model, circleBackground, circle, x, y)
    {
        if(choose)
        {
            desk.indexAt(x, y)
            model.ball = lastColor
            circleBackground.color = getColor(model.ball)
            circle.source = "qrc:/icons/res/icons/circle_empty.png"

        }

    lastColor = 0
    choose = false
    }

    function getColor(value)
    {
        console.log(value)
        var color
        console.log("VALUE COLOR", value);
        if (value === 0) return "transparent";
        if (value === 1) return "red";
        if (value === 2) return "orange";
        if (value === 3) return "yellow";
        if (value === 4) return "green";

    }

}
