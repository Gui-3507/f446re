# base do docker
FROM debian:bookworm-slim

# descricoes
LABEL description="Toolchain ARM"
LABEL maintainer="Guilherme"

# Run execute durante o build da imagem
# cada RUN cria uma camada e a ultima linha serve para 
# apagar o cache do apt na camada final
RUN apt-get update && apt-get install -y --no-install-recommends \
 gcc-arm-none-eabi \
 binutils-arm-none-eabi \
 gdb-multiarch \
 openocd \
 stlink-tools \
 make \
 && rm -rf /var/lib/apt/lists/*

# Workdir define a pasta padrao dentro do container
# quando usar a copia de voluma da pasta com os codigos
# no WSL para o container, os arquivos vao para essa
# pasta '/project'
WORKDIR /project

# Cmd define os comandos padrao do container iniciado sem argumentos
CMD ["make"]