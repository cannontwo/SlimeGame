#include "CAppStateMessage.h"

CAppStateMessage::CAppStateMessage() {
}

CAppStateMessage::CAppStateMessage(int message) {
    intMessage = message;
}

CAppStateMessage::CAppStateMessage(bool message) {
    boolMessage = message;
}

CAppStateMessage::CAppStateMessage(char* message) {
    stringMessage = message;
}

void CAppStateMessage::SetType(int Type) {
    TargetState = Type;
}

int CAppStateMessage::GetType() {
    return TargetState;
}
