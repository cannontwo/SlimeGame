#ifndef __CAPPSTATEMESSAGE_H__
    #define __CAPPSTATEMESSAGE_H__

template <class Type>
class CAppStateMessage {
    public:
        CAppStateMessage(Type message);

        Type GetMessage();

    private:
        Type contents;
};

#endif
