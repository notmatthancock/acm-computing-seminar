# This is a python script to create the figures
# using `matplotlib`.

import numpy as np
import matplotlib.pyplot as plt
plt.style.use('classic')


title = {'forw': "Forward Difference",
         'back': "Backward Difference",
         'cent': "Central Difference"}

linestyles = ['-ok', '-^k']

# Create plots for function 1 first.
def make_plots(func):
    assert func in ['f1', 'f2']

    fig, ax = plt.subplots(1, 3, figsize=(16,8))

    if func == 'f1':
        xs = ['1.0', '2.0']
    else:
        xs = ['1.1', '2.2']

    for i,diff_type in enumerate(['forw', 'back', 'cent']):
        for j,x in enumerate(xs):
            D = np.genfromtxt('../../data/%s-%s-%s-h-and-errs.txt' % 
                              (diff_type, func, x))
            ax[i].plot(D[:,0], D[:,1], linestyles[j], label="$x=%s$"%x)

        if i==0:
            ax[i].set_ylabel('Absolute Error')
        ax[i].set_title(title[diff_type])
        ax[i].set_xscale('log'); ax[i].set_yscale('log')
        ax[i].set_xlabel('$h$', fontsize=20)
        ax[i].grid('on')
        ax[i].legend(loc=2)
        ax[i].set_xlim(1e-7, 1e-1)
        ax[i].set_ylim(1e-14, 1e-1)

    if func == 'f1':
        stitle = "$f(x) = \\sin(x)$" 
    else:
        stitle = "$f(x) = \\exp(-0.5x^2)$" 

    fig.savefig('../%s.pdf'%func, bbox_inches='tight')
    #plt.show()

make_plots('f1')
make_plots('f2')
