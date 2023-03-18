#include <util/application.h>
#include <util/clipboard.h>
#include <util/message.h>
#include <sys/stat.h>
#include <util/optionparser.h>
#include <unistd.h>

int is_file(const char *path)
{
    struct stat s;
    stat(path, &s);
    return S_ISREG(s.st_mode);
}

void usage()
{
    printf("\n");
    printf("Copies stdin/file to clipboard\n");
    printf("----------------------------\nExamples\n----------------------------\n");
    printf("cat file | cbcopy - \tCopy from stdin\n");
    printf("cbcopy file.txt\t\tCopy from file\n");
    printf("----------------------------\n\n");
    exit(0);
}


class Application : public os::Application
{
public:
    Application(int argc, char **argv) : os::Application("x-vnd.copy-clipboard")
    {
        if (argc == 1)
        {
            usage();;
        }
        else
        {
            os::String cBuffer = "";
            os::Clipboard clipboard;
            FILE *fin = NULL;

            if (os::String(argv[1])[0] == '-')
            {
                fin = stdin;
            }
            else
            {
                if (is_file(argv[1]))
                {
                    fin = fopen(argv[1], "r");
                }
            }

            if (fin != NULL)
            {
                char buffer[1024];
                while (fgets(buffer, 1024, fin) != NULL)
                {
                    cBuffer += buffer;
                }
                fclose(fin);

                if (cBuffer != "")
                {
                    //We need to lock a clipboard then we need to add the text
                    clipboard.Lock();
                    clipboard.Clear();
                    os::Message *data = clipboard.GetData();
                    data->AddString("text/plain", cBuffer);
                    clipboard.Commit();
                    clipboard.Unlock();
                }
            }
        }
        exit(0);
    }
};

int main(int argc, char **argv)
{
    Application app = Application(argc, argv);
    return app.Run();
}

