#ifndef __CAPPSTATEMESSAGE_H__
    #define __CAPPSTATEMESSAGE_H__

class CAppStateMessage {
    public:
        CAppStateMessage();
        CAppStateMessage(bool message);
        CAppStateMessage(char* message);
        CAppStateMessage(int message);

        void SetType(int Type);

        int GetType();

    public:
        bool boolMessage;
        char* stringMessage;
        int intMessage;

    private:
        int TargetState;
};

#endif
