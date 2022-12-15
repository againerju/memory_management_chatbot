#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////

    // Copy constructor
    ChatBot(const ChatBot &src);

    // Copy assignment operator
    ChatBot &operator=(const ChatBot &src);

    // Move constructor
    ChatBot(ChatBot &&src);

    // Move assignment
    ChatBot &operator=(ChatBot &&src);

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    void SetImageHandle(wxBitmap * image) {_image = image;};


    wxBitmap  *GetImageHandle() const {return _image;};
    GraphNode *GetCurrentNode() const {return _currentNode;};
    GraphNode *GetRootNode() const {return _rootNode;}
    ChatLogic *GetChatLogicHandle() const {return _chatLogic;};

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
