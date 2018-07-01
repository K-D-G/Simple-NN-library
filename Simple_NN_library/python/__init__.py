
from further_maths import*

from functions.loss_functions.classification import*
from functions.loss_functions.hinge import*
from functions.loss_functions.other_functions import*
from functions.loss_functions.regressive import*

from functions.optimisers.adam import*
from functions.optimisers.SGD import*

from functions.activation_functions import*

from networks.node import*
from networks.feed_forward import*

_export=set(['__version__', '__author__'])
__version__="1.0"
__author__="K-D-G (https://k-d-g.github.io/ or https://github.com/K-D-G)"
__all__=[s for s in dir() if s in _export or not s.startswith('_')]
