const { createInterface } = require('readline');
const rl = createInterface({
    input: process.stdin,
    output: process.stdout,
});

let currentUser = null;

class WalletUser {
    constructor(username, password) {
        this.username = username;
        this.password = password;
        this.balance = 0.0;
        this.transactions = [];
    }
}

function prompt(questionText) {
    return new Promise((resolve) => {
        rl.question(questionText, (answer) => {
            resolve(answer.trim());
        });
    });
}

async function createUser() {
    console.log("Entrez un nom d'utilisateur : ");
    const username = await prompt('');

    console.log("Entrez un mot de passe : ");
    const password = await prompt('');

    currentUser = new WalletUser(username, password);
    console.log("Compte créé avec succès !");
}

async function loginUser() {
    console.log("Entrez le nom d'utilisateur : ");
    const username = await prompt('');

    console.log("Entrez le mot de passe : ");
    const password = await prompt('');

    // Vérifier si l'utilisateur existe (simulé ici avec un utilisateur fixe)
    if (username === currentUser.username && password === currentUser.password) {
        //currentUser = new WalletUser(username, password);
        console.log("Connexion réussie !");
        showMainMenu();
    } else {
        console.log("Identifiants incorrects. Veuillez réessayer.");
    }
}

async function showMainMenu() {
    while (true) {
        console.log("\nMenu Principal : ");
        console.log("1. Affichage du Solde");
        console.log("2. Historique des Transactions");
        console.log("3. Dépôt d'Argent");
        console.log("4. Retrait d'Argent");
        console.log("5. Transfert d'Argent");
        console.log("6. Déconnexion");

        const choice = parseInt(await prompt(''));

        switch (choice) {
            case 1:
                displayBalance();
                break;
            case 2:
                showTransactionHistory();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                withdrawMoney();
                break;
            case 5:
                transferMoney();
                break;
            case 6:
                console.log("Déconnexion...");
                currentUser = null;
                return;
            default:
                console.log("Choix invalide. Veuillez réessayer.");
        }
        break
    }
}

function displayBalance() {
    console.log("Solde actuel : $" + currentUser.balance);
    showMainMenu()
}

function showTransactionHistory() {
    console.log("Historique des transactions : ");
    currentUser.transactions.forEach(transaction => console.log(transaction));
    showMainMenu()
}

async function depositMoney() {
    console.log("Entrez le montant à déposer : ");
    const amount = parseFloat(await prompt(''));
    currentUser.balance += amount;
    currentUser.transactions.push("Dépôt de $" + amount);
    console.log("Dépôt réussi !");
    showMainMenu()
}

async function withdrawMoney() {
    console.log("Entrez le montant à retirer : ");
    const amount = parseFloat(await prompt(''));
    if (currentUser.balance >= amount) {
        currentUser.balance -= amount;
        currentUser.transactions.push("Retrait de $" + amount);
        console.log("Retrait réussi !");
    } else {
        console.log("Solde insuffisant.");
    }
    showMainMenu()
}

async function transferMoney() {
    console.log("Entrez le nom d'utilisateur du destinataire : ");
    const recipient = await prompt('');

    console.log("Entrez le montant à transférer : ");
    const amount = parseFloat(await prompt(''));

    if (currentUser.balance >= amount) {
        currentUser.balance -= amount;
        currentUser.transactions.push("Transfert de $" + amount + " à " + recipient);
        console.log("Transfert réussi !");
    } else {
        console.log("Solde insuffisant.");
    }
    showMainMenu()
}

async function run() {
    while (true) {
        console.log("1. Création de Compte");
        console.log("2. Connexion");
        console.log("3. Quitter");

        const choice = parseInt(await prompt(''));

        switch (choice) {
            case 1:
                await createUser();
                break;
            case 2:
                await loginUser();
                break;
            case 3:
                console.log("Au revoir !");
                process.exit(0);
            default:
                console.log("Choix invalide. Veuillez réessayer.");
        }
    }
}

run();
