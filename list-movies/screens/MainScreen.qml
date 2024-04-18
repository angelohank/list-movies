import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQml 2.15

import "../custom"
import  MainScreenControl 1.0

Item {
    id: root

    signal showDetail( var movie )

    function doStart() {
        control.doStart()
    }

    Component.onCompleted: {
        control.doStart()
    }

    MainScreenControl {
        id: control

        onMovies: function( movies ) {
            listView.model = movies
        }

        onShowDetail: function( movie ) {
            root.showDetail( movie )
        }
    }

    Rectangle {
        id: background
        anchors.fill: parent
        color: "#2E2E2E"

        Column {
            id: container

            anchors.fill: parent
            spacing: 10
            anchors.margins: 15

            SearchField {
                id: searchField
                height: parent.height * 0.07
                width: parent.width

                anchors.horizontalCenter: parent.horizontalCenter

                onSearch: function( filter ) {
                    if( filter !== "" ) {
                        control.search( filter )
                    } else {
                        control.doStart()
                    }
                }
            }

            Divider {
                width: parent.width
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: session
                text: control.sessionDescription
                anchors.left: searchField.left
                color: "#D6D6D6"
                font {
                    weight: Font.Thin
                    pixelSize: root.height * 0.03
                    family: "Helvetica"
                }
            }

            Component {
                id: moviePreviewComponent

                MoviePreview {
                    height: 70
                    width: parent.width

                    src: modelData.show.imagem
                    name: modelData.show.nome
                    average: modelData.show.average

                    onSelected: {
                        control.selectedMovie( index )
                    }
                }
            }

            ListView {
                id: listView

                height: parent.height
                width: parent.width

                delegate: moviePreviewComponent
            }
        }
    }


}
