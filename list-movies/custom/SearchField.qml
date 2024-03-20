import QtQuick 2.15

Row {
    id: root

    spacing: 10

    TextFieldCustom {
        id: textField

        height: 50
        width: 240
    }

    ButtonCustom {
        id: searchButton

        height: textField.height
        width: textField.height
        src: "qrc:/resources/images/SEARCH-ICON.png"

        onClicked: {
            //TODO: realizar filtro
        }
    }
}
