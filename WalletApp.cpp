#include <iostream>
#include <vector>

class WalletUser {
public:
    std::string username;
    std::string password;
    double balance;
    std::vector<std::string> transactions;

    WalletUser(std::string username, std::string password) {
        this->username = username;
        this->password = password;
        this->balance = 0.0;
    }
};

WalletUser* current_user = nullptr;

// Déclaration des fonctions
void show_main_menu();
void display_balance();
void show_transaction_history();
void deposit_money();
void withdraw_money();
void transfer_money();

void create_user() {
    std::cout << "Entrez un nom d'utilisateur : ";
    std::string username;
    std::cin >> username;

    std::cout << "Entrez un mot de passe : ";
    std::string password;
    std::cin >> password;

    current_user = new WalletUser(username, password);
    std::cout << "Compte créé avec succès !" << std::endl;
}

void login_user() {
    std::cout << "Entrez le nom d'utilisateur : ";
    std::string username;
    std::cin >> username;

    std::cout << "Entrez le mot de passe : ";
    std::string password;
    std::cin >> password;

    if (current_user != nullptr && username == current_user->username && password == current_user->password) {
        std::cout << "Connexion réussie !" << std::endl;
        show_main_menu();
    } else {
        std::cout << "Identifiants incorrects. Veuillez réessayer." << std::endl;
    }
}

void show_main_menu() {
    while (true) {
        std::cout << "\nMenu Principal :" << std::endl;
        std::cout << "1. Afficher le Solde" << std::endl;
        std::cout << "2. Historique des Transactions" << std::endl;
        std::cout << "3. Déposer de l'Argent" << std::endl;
        std::cout << "4. Retirer de l'Argent" << std::endl;
        std::cout << "5. Transférer de l'Argent" << std::endl;
        std::cout << "6. Se Déconnecter" << std::endl;

        int choice;
        std::cout << "Entrez votre choix : ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                display_balance();
                break;
            case 2:
                show_transaction_history();
                break;
            case 3:
                deposit_money();
                break;
            case 4:
                withdraw_money();
                break;
            case 5:
                transfer_money();
                break;
            case 6:
                std::cout << "Déconnexion..." << std::endl;
                delete current_user;
                current_user = nullptr;
                return;
            default:
                std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
        }
    }
}

void display_balance() {
    std::cout << "Solde actuel : $" << current_user->balance << std::endl;
}

void show_transaction_history() {
    std::cout << "Historique des transactions :" << std::endl;
    for (const std::string& transaction : current_user->transactions) {
        std::cout << transaction << std::endl;
    }
}

void deposit_money() {
    double amount;
    std::cout << "Entrez le montant à déposer : ";
    std::cin >> amount;

    current_user->balance += amount;
    current_user->transactions.push_back("Dépôt de $" + std::to_string(amount));
    std::cout << "Dépôt réussi !" << std::endl;
}

void withdraw_money() {
    double amount;
    std::cout << "Entrez le montant à retirer : ";
    std::cin >> amount;

    if (current_user->balance >= amount) {
        current_user->balance -= amount;
        current_user->transactions.push_back("Retrait de $" + std::to_string(amount));
        std::cout << "Retrait réussi !" << std::endl;
    } else {
        std::cout << "Solde insuffisant." << std::endl;
    }
}

void transfer_money() {
    std::string recipient;
    double amount;

    std::cout << "Entrez le nom d'utilisateur du destinataire : ";
    std::cin >> recipient;

    std::cout << "Entrez le montant à transférer : ";
    std::cin >> amount;

    if (current_user->balance >= amount) {
        current_user->balance -= amount;
        current_user->transactions.push_back("Transfert de $" + std::to_string(amount) + " à " + recipient);
        std::cout << "Transfert réussi !" << std::endl;
    } else {
        std::cout << "Solde insuffisant." << std::endl;
    }
}

int main() {
    while (true) {
        std::cout << "1. Créer un Compte" << std::endl;
        std::cout << "2. Se Connecter" << std::endl;
        std::cout << "3. Quitter" << std::endl;

        int choice;
        std::cout << "Entrez votre choix : ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                create_user();
                break;
            case 2:
                login_user();
                break;
            case 3:
                std::cout << "Au revoir !" << std::endl;
                return 0;
            default:
                std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
        }
    }

    return 0;
}

