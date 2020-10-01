# Imagem base: minima
FROM alpine:3.12

# Variável de ambiente pra codificação
ENV LANG=C.UTF-8

# Instalando pacotes necessários
RUN apk update
RUN apk add flex g++ make bash
 
# Copiando arquivos fonte
COPY . /usr/src/tp1
WORKDIR /usr/src/tp1

# Roda o Make por padrão
CMD ["make"]