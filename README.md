# Projeto Final de Controle e Automação - Sistema de Irrigação Semi-Automático

# Felipe Otávio de Campos - 12511EAU015

# Introdução:

- O projeto visa simplificar a rotina de pessoas que gastam parte de seu tempo realizando atividades de irrigação manualmente, automatizando este ato e controlando o desperdício de água, liberando-a apenas quando necessário.

# Motivação / Objetivos:

- Automatizar a rotina das pessoas que gastam seu tempo com atividades de irrigação.
- Evitar o desperdício de água ativando o sistema apenas quando for necessário.

# Funcionamento:

- O potenciômetro vai simular a umidade do sistema. Seu valor está convertido em uma escala de 0 a 5, e sempre que ele está abaixo de 2, o led verde irá acender, indicando a condição adequada de umidade.

- O LDR vai simular um horário do dia através de determinada quantidade de luz. Se seu valor for menor ou igual a 200, o led vermelho irá acender, indicando que este é o horário adequado.

- O botão funcionará como uma trava do sistema. Enquanto ele não for pressionado, o usuário pode simular os valores de umidade e luz, mas o relé não será ativado. Caso ele for pressionado, o led amarelo irá acender o sistema vai destravar e estará disponível para uso.

- Caso os valores do potenciômetro e do LDR estejam no intervalo adequado (e o sistema esteja destravado pelo botão), o relé, alimentado externamente pela fonte de 5V, irá acender, e com ele a bomba de água será acionada, liberando a água.

# Limitação:

- Como o sistema é uma simulação, ele não será usado da forma que está. A ideia é demonstrar como ele pode ser expandido para uma aplicação real.
