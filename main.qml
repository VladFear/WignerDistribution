import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.11
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("WignerDistribution")

    MenuBar {
        id: menuBar

        Menu {
           title: qsTr("&File")
           Action {
               text: qsTr("&Open...")
               onTriggered: fileDialog.open()
           }

           MenuSeparator { }

           Action { text: qsTr("&Quit") }
       }

       Menu {
           title: qsTr("&Help")
           Action { text: qsTr("&About") }
       }
    }

    RowLayout {
        anchors.fill: parent

        ColumnLayout {
            RowLayout {
                Text { text: "Iterations:"; }

                TextEdit {
                    text: ""
                    visible: true
                }
            }

            RowLayout {
                Text { text: "Radius:"; }

                SpinBox {
                    value: 1
                    enabled: false
                }
            }

            RowLayout {
                Text { text: "Intervals:"; }

                SpinBox {
                    value: 20
                    from: 10
                    to: 40
                }
            }
        }
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home

        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
        }
    }
}
