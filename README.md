<div id="top"></div>

<!-- PROJECT SHIELDS -->
[![GitHub repo size][reposize-shield]](#)
[![GitHub language count][languagescount-shield]](#)
[![Contributors][contributors-shield]][contributors-url]
[![Stargazers][stars-shield]][stars-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]
[![Gmail][gmail-shield]][gmail-url]






<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/RamMichaeli17/Erdos-Renyl-Model-for-generating-Random-Graphs">
    <img src="https://user-images.githubusercontent.com/62435713/182847026-064b04f7-74d1-469c-a502-b8b100e6433e.png" alt="Logo" width="140" height="140">
  </a>

<h3 align="center">Algorithms 2 Project: "Erdos Renyl Model (for generating Random Graphs)"</h3>

  <p align="center">
    Random graphs help in analyzing complex networks. <br>
    In a random graph, the quantities of nodes and arcs are random variables defined according to a given probabilistic model. <br>
    In this project we will explore properties of undirected random graphs in the Erdos Renyl model. <br>
    In this model, the number of nodes in a graph (we will mark it with V) is fixed and given in advance.<br>
    However, every edge between a pair of nodes will appear in the graph with probability P independently of the other edges, where P - is a parameter of the model.
    <br />
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#build-requirements">Build Requirements</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contributors">Contributors</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>


<!-- ABOUT THE PROJECT -->
## About The Project

![image](https://user-images.githubusercontent.com/62435713/182851861-4c8f2ace-363c-4353-97f8-f127a38a9413.png)

In the 1st part of this project, 4 main tasks are answered:
1. Write a "build_random_graph" function that accepts V and P and returns a random graph with V nodes where each edge will appear in the graph with probability P (you must explain which representation you chose for graphs and why).
2. Write a function called "diameter" that accepts a graph and returns its diameter (the implementation rationale must be explained).
3. Write a function called "Is_Isolated" that receives a graph and returns 1 if the graph has at least one node without neighbors, otherwise the function returns 0.
4. Write a function called "connectivity" that receives a graph and returns 1 if the graph is connected, otherwise the function returns 0.

In the 2nd part of the project we would like to test properties of random graphs with the help of simulation. <br>
For each of the features listed above: <br>
A list of 10 possible values ​​for P must be selected - so that half of the P values ​​are greater than the threshold and half of the values ​​are smaller. <br>
For each of the features, 500 random graphs should be generated for V=1000 and for each of the P's (Total 5000 for each property). You must count how many graphs satisfy the property and how many do not. <br> <br>
In this project you may find several subjects such as: <br>
1. Graph bindings.
2. Graph diameter.
3. An isolated node in a graph.
4. Random graphs.
5. Probability.
6. Simulation.
7. Threshold values.
8. CSV files.
9. Calculation algorithms on graphs.


<p align="right">(<a href="#top">back to top</a>)</p>


## Build Requirements

### Visual Studio 2017

 * *Community*, *Professional* or *Enterprise* Edition
 * VC++ 2017 latest v141 tools
 * Visual C++ compilers and libraries for (ARM, ARM64)
 * Windows XP support for C++
 * Visual C++ ATL for (x86 and x64, ARM, ARM64)
 * Windows 10 SDK

### Visual Studio 2019

 * *Community*, *Professional* or *Enterprise* Edition
 * MSVC v142 - VS 2019 C++ (x64/x86, ARM, ARM64) build tools (Latest)
 * C++ ATL for latest v142 build tools (x86 & x64, ARM, ARM64)
 * Windows 10 SDK

### Visual Studio 2022

 * *Community*, *Professional* or *Enterprise* Edition
 * MSVC v143 Buildtools (x64/x86, ARM, ARM64)
 * C++ ATL for latest v143 build tools (x64/x86, ARM, ARM64)
 * Windows 10 SDK

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

Follow these simple steps:

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/RamMichaeli17/Erdos-Renyl-Model-for-generating-Random-Graphs.git
   ```
2. Run the program
   ```sh
   change the configuration to "Release" (x86 or x64) and press "Local Windows Debugger"
   ```
   ![image](https://user-images.githubusercontent.com/62435713/182854648-45c09a3b-3d2c-4d79-afe0-dc510786531e.png)
3. Watch the results on the opened cmd window:
  ![image](https://user-images.githubusercontent.com/62435713/182908581-8026de46-6dae-495c-879a-bc767922ff20.png)



<p align="right">(<a href="#top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage
[**Click here for a detailed explanation of all the functions in the program and the analysis of the results in the Hebrew language (it is recommended to use some translation software such as Google Translate in order to translate into another language).**](https://github.com/RamMichaeli17/Erdos-Renyl-Model-for-generating-Random-Graphs/raw/master/Erdos%20Renyl%20Model%20(for%20generating%20Random%20Graphs)%20ReadMe.pdf)

![Just Draw It - Demo Gif](https://github.com/RamMichaeli17/Erdos-Renyl-Model-for-generating-Random-Graphs/raw/master/usage.gif)



_For more examples, please refer to the [Documentation](https://github.com/RamMichaeli17/Erdos-Renyl-Model-for-generating-Random-Graphs/blob/master/Erdos%20Renyl%20Model%20(for%20generating%20Random%20Graphs).zip?raw=true)_

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- LICENSE -->
## License

Distributed under the MIT License. See [`LICENSE.txt`](https://github.com/RamMichaeli17/Erdos-Renyl-Model-for-generating-Random-Graphs/blob/master/LICENSE.txt) for more information.

<p align="right">(<a href="#top">back to top</a>)</p>



## Contributors

We thank the following people who contributed to this project:


<table>
  <tr>
    <td align="center">
      <a href="https://github.com/RamMichaeli17">
        <img src="https://avatars.githubusercontent.com/u/62435713?v=4" width="100px;"/><br>
        <sub>
          <b>Ram Michaeli</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/Gal1997">
        <img src="https://avatars.githubusercontent.com/u/66265894?v=4" width="100px;"/><br>
        <sub>
          <b>Gal Israeli</b>
        </sub>
      </a>
    </td>
  </tr>
</table>

<p align="right">(<a href="#top">back to top</a>)</p>




<!-- CONTACT -->
## Contact

Ram Michaeli - ram153486@gmail.com

Project Link: [https://github.com/RamMichaeli17/Erdos-Renyl-Model-for-generating-Random-Graphs](https://github.com/RamMichaeli17/Erdos-Renyl-Model-for-generating-Random-Graphs)

<a href="mailto:ram153486@gmail.com"><img src="https://img.shields.io/twitter/url?label=Gmail%3A%20ram153486%40gmail.com&logo=gmail&style=social&url=https%3A%2F%2Fmailto%3Aram153486%40gmail.com"/></a>
<a href="https://linkedin.com/in/ram-michaeli"><img src="https://img.shields.io/twitter/url?label=ram%20Michaeli&logo=linkedin&style=social&url=https%3A%2F%2Fmailto%3Aram153486%40gmail.com"/></a>
<p align="right">(<a href="#top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
[reposize-shield]: https://img.shields.io/github/repo-size/RamMichaeli17/Erdos-Renyl-Model-for-generating-Random-Graphs?style=for-the-badge

[languagescount-shield]: https://img.shields.io/github/languages/count/RamMichaeli17/Erdos-Renyl-Model-for-generating-Random-Graphs?style=for-the-badge

[contributors-shield]: https://img.shields.io/github/contributors/RamMichaeli17/Erdos-Renyl-Model-for-generating-Random-Graphs.svg?style=for-the-badge

[contributors-url]: https://github.com/RamMichaeli17/Erdos-Renyl-Model-for-generating-Random-Graphs/graphs/contributors

[stars-shield]: https://img.shields.io/github/stars/RamMichaeli17/Erdos-Renyl-Model-for-generating-Random-Graphs.svg?style=for-the-badge

[stars-url]: https://github.com/RamMichaeli17/Erdos-Renyl-Model-for-generating-Random-Graphs/stargazers

[license-shield]: https://img.shields.io/github/license/RamMichaeli17/Erdos-Renyl-Model-for-generating-Random-Graphs.svg?style=for-the-badge

[license-url]: https://github.com/RamMichaeli17/Erdos-Renyl-Model-for-generating-Random-Graphs/blob/master/LICENSE.txt

[linkedin-shield]: https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white

[linkedin-url]: https://linkedin.com/in/ram-michaeli

[gmail-shield]: https://img.shields.io/badge/ram153486@gmail.com-D14836?style=for-the-badge&logo=gmail&logoColor=white

[gmail-url]: mailto:ram153486@gmail.com

[product-screenshot]: images/screenshot.png
