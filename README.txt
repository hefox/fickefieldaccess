Fickle field access is a set of modules to control access to fields based on various settings.

It has one configuration for the field: which mode to protect the field with. (Currently only taxonomyfieldaccess). 

The basic dynamic parts of each potential field access are
1) skip access; functions to test whether to skip checking this access. For example, fickle skip access perm checks on whether a certain permission is set. Cookie skip access checks on a cookie.
2) sad response: function to call when access is denied; fro example cookie skip access calls uses it to display a status message with a link to set cookie. 

Each access check also has an access function that actually checks the access (assuming the skip access hasn't been called).

One fickle field access module (besides the base) most be enabled to use this, or else it's quite useless. 