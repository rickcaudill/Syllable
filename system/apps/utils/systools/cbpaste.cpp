#include <stdio.h>
#include <util/application.h>
#include <util/message.h>
#include <util/clipboard.h>


void usage()
{
    printf("\n");
    printf("paste to stdout from clipboard\n");
    printf("----------------------------\nExamples\n----------------------------\n");
    printf("cbpaste $(echo 'test' | cbcopy - ) - \tPaste from stdout the result  of 'test' from the clipboard\n");
    printf("----------------------------\n\n");
    exit(0);
}


class Application : public os::Application
{
public:
    Application(int argc, char **argv) : os::Application("x-vnd.paste-clipboard")
    {
        //NOTE: We need to lock a clipboard then we need to add the text
        os::String cBuffer;
        os::Clipboard clipboard;
        clipboard.Lock();
        os::Message *data = clipboard.GetData();
        data->FindString("text/plain", &cBuffer);
        clipboard.Unlock();

        printf("%s", cBuffer.c_str());
        exit(0);
    }
};


int main(int argc, char **argv)
{
    Application app = Application(argc, argv);
    return app.Run();
}

