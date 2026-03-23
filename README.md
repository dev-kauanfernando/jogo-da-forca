# 🎯 Jogo da Forca em C

Projeto simples de um jogo da forca desenvolvido na linguagem C, utilizando conceitos fundamentais de programação como funções, arrays, estruturas de repetição e manipulação de strings.

---

## 📌 Funcionalidades

- Escolher palavra aleatória automaticamente  
- Permitir que o usuário digite uma palavra personalizada  
- Sistema de dicas para cada palavra  
- Contagem de tentativas  
- Exibição visual da forca (ASCII)  
- Verificação de vitória ou derrota  
- Opção de jogar novamente  

---

## 🧠 Conceitos utilizados

- Manipulação de strings (`string.h`)
- Funções e modularização
- Estruturas condicionais (`if`, `switch`)
- Laços de repetição (`for`, `while`)
- Geração de números aleatórios (`rand`)
- Conversão de caracteres (`toupper`)
- Entrada e saída de dados (`stdio.h`)

---

## 🎮 Como jogar

1. Ao iniciar o programa, escolha uma opção:
   - `1` → Palavra aleatória
   - `2` → Digitar sua própria palavra

2. O jogo exibirá:
   - A palavra oculta (`_ _ _`)
   - Uma dica
   - Número de tentativas restantes

3. Digite uma letra por vez.

4. O jogo termina quando:
   - Você descobre a palavra (vitória 🎉)
   - Suas tentativas acabam (derrota 💀)

---

## 🖥️ Exemplo de execução

```
MENU FORCA

1- Sortear palavra
2- Digitar palavra

Digite uma opcao: 1

Palavra: _ _ _ _ _
Dica: Animal

Tentativas restantes: 6

Digite uma letra:
```

---

## ⚙️ Como compilar e executar

### 🔧 Requisitos
- Compilador C (GCC recomendado)

### ▶️ Compilar
```bash
gcc jogoDaForca.c -o forca
```

### ▶️ Executar
```bash
./forca
```

---

## ⚠️ Observações

- O comando `system("cls")` funciona no Windows.  
  Para Linux/Mac, substitua por:
  ```c
  system("clear");
  ```
- O uso de `fflush(stdin)` não é recomendado em padrão C, podendo gerar comportamento indefinido.

---

## 🚀 Melhorias futuras

- [ ] Suporte a palavras com espaço
- [ ] Interface gráfica
- [ ] Ranking de jogadores
- [ ] Sistema de níveis de dificuldade
- [ ] Melhor validação de entrada

---

## 👨‍💻 Autor

Kauan Fernando
