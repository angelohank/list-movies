import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQml 2.15

import "./screens"

ApplicationWindow {
    id: root

    width: 400
    height: 600
    visible: true
    title: "List Movies"

    StackView {
        id: stack
        initialItem: mainScreenComponent
        anchors.fill: parent
    }

    Component {
        id: mainScreenComponent

        MainScreen {
            id: mainScreen
            anchors.fill: parent

            onShowDetail: function( movie ) {
                stack.push( detailScreenComponent )
                stack.currentItem.setModel( movie )
                stack.currentItem.doStart();
            }
        }
    }

    Component {
        id: detailScreenComponent

        DetailScreen {
            id: detailScreen
            anchors.fill: parent

            onFinish: {
                stack.pop()
            }
        }
    }
}

