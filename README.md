# biai
Implementation of a neural network that calculates an object's trajectory

Done:
* Structure of the net
* Testing use case, text file handling
* Test data and results for simple xor
* Interface that launches all needed functionalities
* Parsing arguments for a function
* Normalizing net values
* Saving net to file (as text)
* Scaling visualization in real time using interface inputs
* Drawing input functions
* Net testing flow
* Drawing test results
* Different net sizes handling

TODO:
* Transfer functions research
* Remove the weird chart argument jump after aproximation
* Error and improper commands handling
* Input functions research
* Namechange in groupbox "testdata" for "training data"
* Parsing more functions: i.e. sin, log
* Output log pretty print
* Interface smoothing

TODO after last release:
* Analysis of other net input functions, other than a square function
* Transfer functions
* Mean square error of calculated points and points taken from the source (part of the learning data not used for learning)
* Test net behaviour for points from i.e. sinus function, that curve in y axis in both diretions intermittently
* Create end report, and in it:
  1. Implementation description (external + internal specification, description of most important classes and methods and their uses/arguments)
  2. Research aspect - examples of specific, interesting cases, test analysis, project conclusions
