import QtQuick 2.15

Row {
    id: root

    spacing: 10

    TextFieldCustom {
        id: textField

        height: 30
        width: 240
    }

    ButtonCustom {
        id: searchButton

        height: textField.height
        width: textField.height

        onClicked: {
            //TODO: realizar filtro
        }
    }
}
