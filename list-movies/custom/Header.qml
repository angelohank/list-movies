import QtQuick 2.15

Column {
    id: root

    width: 50
    height: 50

    property string sessionDescription: ""

    signal search( var filter )
    signal doStart

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
            if( filter !== "" ) {
                root.search( filter )
            } else {
                root.doStart()
            }
        }
    }

    Divider {
        width: parent.width - 10
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: session
        text: root.sessionDescription

        anchors.left: searchField.left
        font {
            weight: Font.Thin
            pixelSize: root.height * 0.03
            family: "Helvetica"
            italic: true
        }
    }
}
