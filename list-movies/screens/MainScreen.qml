import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQml 2.15

import "../custom"
import  MainScreenControl 1.0

Item {
    id: root

    MainScreenControl {
        id: control
    }

    Flickable {
        id: flickable

        anchors.fill: parent
        contentWidth: container.width
        contentHeight: container.height
        flickableDirection: Flickable.VerticalFlick

        onFlickEnded: {
            flickable.originX = contentX
            flickable.originY = contentY
        }

        Column {
            id: container

            anchors {
                fill: parent
                topMargin: 15
                leftMargin: 10
            }

            spacing: 15

            SearchField {
                id: searchField
                height: parent.height * 0.07
                width: parent.width

                anchors.horizontalCenter: parent.horizontalCenter

                onSearch: function( filter ) {
                    control.search( filter )
                }
            }

            Divider {
                width: parent.width - 10
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                text: control.sessionDescription

                anchors.left: searchField.left
                font {
                    weight: Font.Thin
                    pixelSize: root.height * 0.03
                    family: "Helvetica"
                    italic: true
                }
            }

            Repeater {
                id: repeater
                model: control.qtMovies

                MoviePreview {
                    height: 70
                    width: parent.width
                    src: "https://static.tvmaze.com/uploads/images/original_untouched/191/478539.jpg"

                    onSelected: function( index ) {
                        console.log(index)
                    }
                }
            }
        }
    }
}
