````markdown
# 🔐 Base64 Encoder & Decoder

## 📖 Description
Ce projet contient une implémentation maison de l’algorithme Base64, permettant :
- Comprendre vraiment l'algorithme et la logique derriere.
- L’encodage d’une chaîne en Base64
- Le décodage d’une chaîne depuis Base64

👉 Le but est pédagogique : ne pas utiliser de librairies natives (`base64`, etc.), mais comprendre et coder l’algo.

---

## ⚙️ Fonctionnalités
- Encodage de texte ASCII en Base64
- Décodage Base64 vers texte lisible
- Gestion du **padding** `=`
- Support des caractères spéciaux

---

## 🚀 Utilisation
si vous etes sur linux utiliser 
```bash
g++ -o bin dgse_chall.cpp
```

### 🧩 Exemple d’encodage
```bash
Input  : HelloWorld
Output : SGVsbG9Xb3JsZA==
````

### 🧩 Exemple de décodage

```bash
Input  : SGVsbG9Xb3JsZA==
Output : HelloWorld
```

---

## 🧪 Challenge realiser

Capturer le QR code sur la photo et puis nous avons une chaine de caractere suivante :

```
Q29tbWVudCByZXRyb3V2ZXIgbGVzIGVudHJlcHJpc2VzIHBpcmF0w6llcyBwYXIgbGUgcmFuc29td2FyZSBBa2lyYSA/Vm91cyB0cm91dmV6IGxhIHF1ZXN0aW9uIGZhY2lsZSA/IFBvc3R1bGV6IHN1ciBjZXR0ZSBhbm5vbmNlIGV0IHZlbmV6IHRyYXZhaWxsZXIgYXZlYyBub3VzICE=
```
Nous aurions pu decoder directement la chaine en utilisant l'outil cyberchef ou bien avec la commande bash :
```bash
echo "Q29tbWVudCByZXRyb3V2ZXIgbGVzIGVudHJlcHJpc2VzIHBpcmF0w6llcyBwYXIgbGUgcmFuc29td2FyZSBBa2lyYSA/Vm91cyB0cm91dmV6IGxhIHF1ZXN0aW9uIGZhY2lsZSA/IFBvc3R1bGV6IHN1ciBjZXR0ZSBhbm5vbmNlIGV0IHZlbmV6IHRyYXZhaWxsZXIgYXZlYyBub3VzICE=" | base64 -d
```
mais nous avions pas ce coter fun de comment fonctionne vraiment l'encodage et le decodage en base64

---

## 🏗️ compréhension de l'algorithme

Parfait, j’ai gardé **ta formulation exacte**, je n’ai fait que corriger les fautes d’orthographe, d’accord ? Voici la version corrigée :

---

Le but de l'encodage base64 est de convertir des données binaires arbitraires en caractères pouvant être transmis en sécurité.
Il utilise 6 bits pour convertir la partie binaire en caractères ASCII.
Comment ?
Nous utilisons 2^6 = 64 caractères composés de 10 chiffres de 0 à 9, de 26 caractères minuscules de a-z et de 26 caractères majuscules de A-Z et de deux caractères `'+'` et `'/'`.

Alphabet utilisé :

```
ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/
```

Le but est de diviser le flux de données en 2 groupes, c'est-à-dire en 3 octets consécutifs ce qui équivaut à 24 bits.
Ensuite nous devons faire la conversion en série en fonction de la taille de la chaîne composée de 6 bits.
C'est ainsi que nous devons convertir chaque groupe de 6 bits en ASCII à l'aide de la table d'encodage : [http://yannklein.free.fr/cours/reseau/conversion.html](http://yannklein.free.fr/cours/reseau/conversion.html)

Attention si la chaîne d'entrée n'est pas un multiple de 3 nous devrions rajouter 2 bits à 0, ce qui fait office de padding et équivaut à un caractère `'='`.
Nous devrions ajouter 4 bits à 0 dont deux caractères `'='` à la chaîne d'entrée avant l'encodage.


---

## Response au challenge 

Nous puvions faire de l'OSINT en parcourant des sites sur le DarkWeb, ou bien des rapport de societe de cybersecurite.
La CISA ou equivalent selon le pays publient des rapports qui citent des entreprises victimes ou des secteurs touches.
On peut se referencer sur le site https://www.ransomware.live/group/akira


## 📂 Structure du projet

```
/base64-project
│── dsge_chall.cpp   # fonction d'encodage
│── README.md    # ce fichier
```

---

## 👨‍💻 Auteur

![C++](https://img.shields.io/badge/C++-17-blue?style=for-the-badge\&logo=c%2B%2B\&logoColor=white)

Projet réalisé dans le cadre d’un challenge d’algorithmie sur l’encodage/décodage **Base64**.

---

<p align="center">
  Made with ❤️ by <b>Hibooxx</b> <br>
  <img src="https://img.shields.io/badge/CyberSecurity-%F0%9F%92%8E-blueviolet?style=for-the-badge" alt="Cyber"/>
</p>
```
