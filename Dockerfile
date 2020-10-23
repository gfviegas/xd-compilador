# Imagem base: minima
FROM alpine:3.12

# Variável de ambiente pra codificação
ENV LANG=C.UTF-8

# Instalando pacotes necessários
RUN apk update
RUN apk add flex g++ make bash

# Copiando arquivos fonte
COPY . /usr/src/tp2
WORKDIR /usr/src/tp2

RUN make

# Roda o Make por padrão
CMD ["bash", "./init.sh"]
