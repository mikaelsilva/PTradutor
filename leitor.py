import PyPDF2

path = "c:\\Nova pasta\\\Projetos Git\\PTradutor\\Computer Organization and Design.pdf"

text = open(path,mode='rb')
reader = PyPDF2.PdfFileReader(text)

count = reader.numPages
lista = []

for i in range(count):
    page = reader.getPage(i)
    word = page.extractText().upper().replace(","," ").replace("."," ").replace("\n"," ").split(' ')
    
    for p in word:
        lista.append(p)
        #print(p)

my_list = list(dict.fromkeys(lista))
print(my_list)

#PROXIMAS ETAPAS SAO:
    #AJUSTAR O DICIONARIO PARA QUE CONTENHA A PALAVRA E QTD
    #CRIAR UM DICIONARIO COM AS PALAVRAS COMO CHAVE, E AS TRADUÇÕES E PORNUNCIA COMO UMA TUPLA NOS VALORES
    #CRIAR UM TERCEIRO DICIONARIO/LISTA/TUPLA (DECIDIR A MELHOR ABORDAGEM) QUE CONTENHA | PALAVRA_INGLES | QTD | TRADUÇÕES |