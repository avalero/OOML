OOML
====

C++ Object Oriented Mechanics Language

What's the OOML
===============

OOML stands for Object Oriented Mechanics Library. 
The OOML is a set of tools written in C++ that allow designers to create mechanical parts using the C++ language.
 * OOML applies the model of Object Oriented Programming to Mechanical Designs. 
 * Parts can be inherited from others. A part can join together other existing parts, and so forth.
 * OOML has up to now no external dependency and can be used in any computer having a standard C++ compiler.

Up to current version OOML generates OpenSCAD code. Using OpenSCAD designers may generate the STL of the parts.

 * OOML is Open Source, you can use it, modify it, share it.

What's the intention of the OOML
================================

 * OOML brings together both the design of pieces through code (as it's done with OpenSCAD) with the programming power 
of an Object Oriented Language as C++.

 * OOML provides a powerful tool for designers to boost their creativity building mechanical parts. 
 * As it uses C++, designers may use any other existing C++ library to calculate, manipulate, create their parts.
 * OOML allow designers to create and share their own Parts Libraries, which will certainly enrich the community.

Up to current version OOML generates only OpenSCAD code. We are working to generate also code for other cad programs such as FreeCad, OpenRave
including a GLViewer, etc.

The reason OOML exports to OpenSCAD is because we were just testing the viability of a C++ library for defining 
things using object oriented programming, giving semantical meaning, etc... 
We did not want to deal with the visualization and STL files... 

Now that it seems it is working we will start making a GL viewer, and generating STLs.. but that's not the real power. 
If the object is semantically and geometrically defined, you could theoretically make whatever you want with it... 
for example exporting to collada, for OpenRAVE, making stress tests...

That's the idea, defining parts from their simple components and their geometrical operations. 
It is like Open SCAD but object oriented.