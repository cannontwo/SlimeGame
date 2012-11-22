#include "CAppStateMessage.h"


CAppStateMessage::CAppStateMessage(Type message) {
    contents = message;
}


Type CAppStateMessage::GetMessage() {
    return message;
}
