# List-Movie

## Descrição do projeto
Este projeto consiste em uma aplicação que consome os dados da uma API, mais especificamente a [API Tv Maze](https://www.tvmaze.com/api), e exibe algumas das informações retornadas em tela.

O backend da aplicação foi desenvolvido usando C++ com Qt Framework ( versão 6.3.1 ), enquanto o frontend foi desenvolvido usando QML.

## Usabilidade
- Ao abrir a aplicação, é exibida uma lista de séries listadas na sessão "Em alta". As informações exibidas nesse preview são:
	- Imagem;
	- Nome;
	- Nota.

- Clicando em cima da série desejada, é exibida uma tela de detalhes, com as seguintes informações:
	- Imagem;
	- Nota;
	- Nome;
	- Gêneros;
	- Descrição.

- Clicando no botão de retorno da tela de detalhes, é retornado para a tela inicial, com as séries "em alta" listadas.
- Ao digitar algo no campo de busca e clicar no botão de pesquisa, as séries listadas em tela são atualizadas para as novas séries retornadas. O comportamento para mostrar os detalhes se mantém.
- Ao clicar no botão de busca sem nenhum conteúdo digitado no campo, são listadas novamente as séreis "em alta".

## Documentação técnica
### Backend:
#### Control
	Camada responsável por conectar o backend ao frontend, de maneira que não deixe as regras de negócio sob responsabilidade da tela ou de camadas mais externas.
	
- MainScreenControl: Conecta as regras de negócio do MainScreenController à MainScreen. Responsável por emitir signals que atualizam as séries a serem exibidas na tela
**Principais métodos:** 
	- **MainScreenControl::search:** método responsável por chamar o MovieController e mandar para a tela as séries retornadas depois da pesquisa;
	- **MainScreenControl::loadInitialMovies:** método responsável por chamar o MovieController e definir a lista de séries iniciais. Essa lista será carregada apenas uma vez durante a execução da aplicação.

#### Controller
	Camada responsável por conter as regras da aplicação, como por exemplo definir a URL a ser passada para que seja feita a request de acordo com os filtros do usuário.

- MoviesController: Por ser uma aplicação bem objetiva, acaba sendo a única classe dessa camada, tendo as responsábilidades descritas acima.
**Principais métodos:**
	- **MoviesController::MoviesConverter:** método recebe um QByteArray, que é convertido em um QJsonDocument e, após isso, em QJsonObject. Esse objeto é passado para o objeto MovieConverter. Após tratamentos de conversão do MovieConverter, o método retorna uma QList<MovieModel*>.
	- **MoviesController::doRequest:** Método responsável por chamar o objeto NetworkRequester, que irá realizar a request. Após finalização da request, o método doRequest chama a conversão dos dados.
	- **MoviesController::searchInitialMovies:** Esse método foi criado para retornar uma lista estática de série pré-definidas. Sua estrutura consiste em uma lista estática de séries, lista essa que será usada para fazer a request buscando cada nome de série contida nela.

#### Converter
- MovieConverter: Converte o objeto principal retornado do JSON para um MovieModel;
- ShowConverter: Converte o objeto "show" retornado do JSON para um ShowModel;
- 
#### Network
	Camada responsável por conter os obejtos e configurações necessárias para realizar as requests da aplicação

#### Model
	Camada responsável por conter as classes que representam os dados retornados da API a serem unitilizados na aplicação
- **MovieModel:** Objeto responsável por armazenar as informações retornadas da request a serem usadas na aplicação
	- Propriedades:
		- Score ( double );
		- Show ( ShowModel );
- **ShowModel:** Objeto responsável por armazenar as informações retornadas dentro da tag "show" do JSON de retorno da API
	- Propriedades:
		- Nome ( string );
		- Descricao ( string );
		- Generos ( list );
		- Average( double );
		- Imagem( string ).

### Frontend:
#### Screens
	Camada responsável por conter os arquivos QML que representam as telas da aplicação
- MainScreen: Tela principal da aplicação, onde são apresentados os previews da séries buscadas e em alta.
- DetailScreen: Tela de detalhes da série selecionada pelo usuário

#### Custom
	Camada responsável por conter componentes personalizados utilizados durante a aplicação
- ButtonCustom;
- SearchField;
- DetailComponent;
- Divider;
- MoviePreview;
- TextFieldCustom
##### OBS: Esta camada poderia ser ainda mais dividida, entre componentes e objetos modelo.
#### Resources
	Camada onde ficam armazenados os arquivos de recurso usados no sistema, como imagens.


## Passo a passo para abrir o projeto
Para executar o projeto, basta clonar o repositório em ou baixar o arquivo .zip disponibilizado pelo próprio GitHub.

#### Versões utilizadas no desenvolvimento
- QtCreator: 8.0.1
- Qt: 6.3.1
- OpenSSL: 3.2.1
- CMake: 3.14

## Trabalhos futuros
 - Testes unitários
   - Converter
   
Alguns pontos nas interfaces deixaram a desejar, como o scroll das séries, que possui alguns problemas para se chegar até o fim
Além disso, alguns pontos das interfaces poderiam ser melhor componentizados, como o header da tela principal.

Além disso, no backend, poderia ter sido criada uma abstração maior na camada Network, criando uma classe para conter apenas o endpoint e uma tratativa melhor para os filtros.

## Bugs e melhorias ##

- #001 [BUG] Ajustar campo de detalhes da série para conteúdo não ultrapassar o campo;
- #002 [BUG] Verificar e corrigir memory leaks;
- #003 [BUG] Ajustar alinhamento do nome da série na tela de preview;
- #004 [BUG] Ajustar scroll que fica cortado na tela de preview;
- #005 [FEAT] Criar e apresentar loading enquanto as séries são carregadas na tela de preview;
- #006 [FEAT] Apresentar loading na transição da tela de preview para a tela de detalhes;
- #007 [FEAT] Recriar visual para ser mais harmonioso e amigável;
- #008 [FEAT] Componentizar header

