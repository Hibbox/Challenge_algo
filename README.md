Parfait 👌 on va lui donner un vrai style “repo open source C++”.
J’ai rajouté le **badge C++**, placé juste au-dessus de ton bloc “Auteur” pour faire pro :

````markdown
# 🔐 Base64 Encoder & Decoder

## 📖 Description
Ce projet contient une implémentation **maison** de l’algorithme Base64, permettant :
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

## 🧪 Jeux de tests

| Texte     | Base64         |
| --------- | -------------- |
| `Hello`   | `SGVsbG8=`     |
| `Base64`  | `QmFzZTY0`     |
| `Python!` | `UHl0aG9uIQ==` |
| `GitHub`  | `R2l0SHVi`     |

---

## 🏗️ Implémentation

Le code est découpé en deux parties principales :

1. **`encode()`** : Convertit le texte en Base64
2. **`decode()`** : Convertit le Base64 en texte original

Alphabet utilisé :

```
ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/
```

---

## 📂 Structure du projet

```
/base64-project
│── encode.cpp   # fonction d'encodage
│── decode.cpp   # fonction de décodage
│── tests/       # cas de tests
│── README.md    # ce fichier
```

---

## 🏆 Bonus

* Implémenter une **interface CLI** (`--encode`, `--decode`)
* Comparer les performances avec la librairie standard
* Ajouter un mode **fichier → fichier**

---

## 👨‍💻 Auteur

![C++](https://img.shields.io/badge/C++-17-blue?style=for-the-badge\&logo=c%2B%2B\&logoColor=white)

Projet réalisé dans le cadre d’un challenge d’algorithmie sur l’encodage/décodage **Base64**.

---

<p align="center">
  Made with ❤️ by <b>Hibooxx</b> <br>
  <img src="https://img.shields.io/badge/Beau%20Gosse-%F0%9F%92%8E-blueviolet?style=for-the-badge" alt="Beau Gosse Badge"/>
</p>
```

---

Tu veux que je te prépare aussi un **badge GitHub Actions (build & tests)**, genre qui s’affiche en vert quand ton code compile, histoire de pousser le côté pro encore plus loin ?
