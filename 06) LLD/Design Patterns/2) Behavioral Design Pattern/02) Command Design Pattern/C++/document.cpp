#include <iostream>
#include <vector> // Include this for std::vector
#include <memory> // Include this for std::unique_ptr

using namespace std;

// Command Interface
class ActionListenerCommand {
public:
    virtual void execute() = 0;
    virtual ~ActionListenerCommand() {}
};

// Receiver - performing the operation
class Document {
public:
    void open() {
        cout << "Document Opened" << endl;
    }

    void save() {
        cout << "Document Saved" << endl;
    }
};

// Concrete Command
class ActionOpen : public ActionListenerCommand {
private:
    Document* doc;

public:
    ActionOpen(Document* document) : doc(document) {}

    void execute() override {
        doc->open();
    }
};

// Concrete Command
class ActionSave : public ActionListenerCommand {
private:
    Document* doc;

public:
    ActionSave(Document* document) : doc(document) {}

    void execute() override {
        doc->save();
    }
};

// Invoker
class MenuOptions {
private:
    vector<unique_ptr<ActionListenerCommand>> commands;

public:
    void addCommand(unique_ptr<ActionListenerCommand> command) {
        commands.push_back(move(command));
    }

    void executeCommands() {
        for (const auto& command : commands) {
            command->execute();
        }
    }
};

int main() {
    Document doc;
    MenuOptions menu;

    // Use unique_ptr for automatic memory management
    menu.addCommand(make_unique<ActionOpen>(&doc));
    menu.addCommand(make_unique<ActionSave>(&doc));
    
    // Client code only adds commands to the menu
    // The invoker (menu) doesn't need to change when new commands are added
    menu.executeCommands();

    return 0;
}
