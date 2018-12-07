# LangtonsAnt

Langton's ant visualization

## How to use
### Setup

To run program you must create config file as `ant_conf_example_1.json` in `./examples` folder. 
In this file you can configure initial states for program.

After you configured file all you need is just run the program with argument of config file path.

*Note: current version supports only field with equal height and width. *

Example: 
    
```bash
./LangtonsAnt path/to/config/file.json
```

### Controls

There are some control buttons:
* `Escape` or `E`: Exit;
* `Space` or `P`: Pause;
* `Plus` or `F`: Speed up;
* `Minus` or `S`: Speed down;
* `Equals` or `D`: Set initial speed.