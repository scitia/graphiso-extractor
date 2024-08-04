# Graphiso-Extractor

<div style="display:flex;justify-content: center;align-items: center;">
<img src="doc/img/scitia_logo.png" alt="Logo of K!Scithia">
</div>

## Table of contents
- [Graphiso-Extractor](#graphiso-extractor)
  - [Table of contents](#table-of-contents)
    - [Introduction ](#introduction-)
    - [Prerequisite ](#prerequisite-)
    - [Database Description ](#database-description-)
    - [Instalation ](#instalation-)
    - [Examples of use ](#examples-of-use-)
    - [References ](#references-)

### Introduction <a name="intro"></a>

This project is intended for graph database extraction for further use with dedicated Python libraries for analysis Graph-Sub-Graph Isomorphism problem and general researches underlie the graph theory. It can be useful for scientific researches, learning graph theory and experiments conduction for scientist as well as science students. It can be used for testing your own improvements of existing graphs algorithms, writing your own and looking for dependencies in/between these beautiful structures.  

### Prerequisite <a name="prerequisite"></a>

Launching this application assume that you have installed on your computer a few required libraries and you use work station with Intel processor that support Math Kernel Library (MKL). In the parenthesis are provided recommended versions of those libraries on which project was tested.
- Armadillo Library (12.8.1)
- Boost Library (1.85.0)
- Intel MKL Library (2024.2)
- GNU (13.2.0)

### Database Description <a name="desc"></a>

You can read PDF article that is attached <a href="doc/papers/database.pdf"><b>here</b></a> in this project.

### Instalation <a name="install"></a>

Before you run <b>install.bat</b> script make sure that you have MKL Library installed on your computer, Boost library built with MinGW and Aramdillo library.

Recommended installation paths are:

- Boost: ``C:/local/boost_1_85_0``
- Armadillo: ``C:/armadillo``
- MKL: default

If you want to customize installation paths - default installation process will failed. You will be forced to modify CMakeLists.txt file in order to amend proper information about location of the above mentioned tools on your computer.

Please familiar with official documentation for above mentioned tools and its installation processess.

After you will install all required tools download original files for databse that are base for conversion process from link <a href="https://drive.google.com/file/d/15rvTVlAcEbyQQkcanH-fQjmrCvQ5zhbv/view?usp=sharing"><b>Download resource</b></a>

At this stage we assume that you have all required tools installed and you physically have required files downloaded from above mentioned link.

Now you can do below steps:

1. Download the source code of this project
```powershell
git clone https://github.com/scitia/graphiso-extractor.git
```

2. Open <b>config.ini</b> file and fill all required iformation about source files location, target location and ground truth files location like in exmaple below:
```ini
[database]
source=c:/db/bin
ground=c:/db/gtr
target=c:/db/csv
```
For <b>source</b> and <b>ground</b> properties you have to point to /bin and /gtr directories respectively of downloaded database.

3. Run installation script:
```powershell
.\install.bat
```

You will be informed about every step of installation. After this process you will be in possession of converted database that you can use in high-level programming languages as python in more comfortable way. This usage will be described in the next section of this documentation.

### Examples of use <a name="use"></a>

An example pair of two isomorphic graphs and vertex maping between them as a map container in center part of drawing:

<img src="doc/img/iso_draw.png" alt="Examples graph and vertex mapping">

I encourage you to use my dedicated python <a href="https://github.com/scitia/graphs"><b>library</b></a> to deal with graphs and automates processing these structures. <b style="color: #d12a2a">Use this installation only if you need to possess files locally on your computer to speed up processing in your researches.</b> 

### References <a name="references"></a>

Conrad Sanderson and Ryan Curtin.
<b><a href="https://arma.sourceforge.net/armadillo_joss_2016.pdf">Armadillo: a template-based C++ library for linear algebra.</a></b>
Journal of Open Source Software, Vol. 1, No. 2, pp. 26, 2016.

Conrad Sanderson and Ryan Curtin.
<b><a href="https://arma.sourceforge.net/armadillo_mca_2019.pdf">Practical Sparse Matrices in C++ with Hybrid Storage and Template-Based Expression Optimisation.</a></b>
Mathematical and Computational Applications, Vol. 24, No. 3, 2019.

P. Foggia, C. Sansone, M. Vento
<b>A Database of Graphs for Isomorphism and Sub-Graph
Isomorphism Benchmarking</b>
Dipartimento di Informatica e Sistemistica - Università di Napoli "Federico II" Via Claudio 21, I-80125 Napoli (Italy)

Cordella, L. P.; Foggia, P.; Sansone, C. Vento, M. (2001)
<b>An Improved Algorithm for Matching Large Graphs</b>
3rd IAPR-TC15 Workshop on Graph-based Representations in Pattern Recognition: 149–159.
