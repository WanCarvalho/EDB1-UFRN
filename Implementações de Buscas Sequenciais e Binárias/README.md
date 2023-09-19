# Atividade de análise empírica

Gere um executável a partir da compilação do main.cpp com alguma implementação do algoritmo de busca (ex.: busca_seq_iter.cpp).

Rode o arquivo executável, direcionando a sua saída para algum arquivo de texto. Ex.: ./bin/bsi.exe > ./data/bsi.csv

Em seguida, rode o script python para gerar o gráfico, passando pela linha de comando o nome do arquivo 'csv' criado no passo anterior. Ex.: python3 ./src/gerador_grafico.py ./data/bsi.csv

Se ao executar o script python aparecer uma mensagem de erro sobre não ter o algum pacote instalado, rode o seguinte comando: python3 -m pip install <nome_do_pacote>