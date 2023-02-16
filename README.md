<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [Purpose](#purpose)
- [Warning](#warning)
- [Project branch strategy](#project-branch-strategy)
- [Recommended versions](#recommended-versions)
- [Codebase](#codebase)
- [Hosting](#hosting)
- [External Resources](#external-resources)
- [Local dev setup using Lando](#local-dev-setup-using-lando)
  - [(Step 1) Get a Pantheon account](#step-1-get-a-pantheon-account)
  - [(Step 2) Install Lando and Docker Desktop](#step-2-install-lando-and-docker-desktop)
  - [(Step 3) Git clone the repo](#step-3-git-clone-the-repo)
  - [(Step 4) Configure Git](#step-4-configure-git)
  - [(Step 5) Configure /etc/hosts](#step-5-configure-etchosts)
  - [(Step 6) Lando start](#step-6-lando-start)
  - [(Step 7) Add SSH key to Pantheon and create machine token](#step-7-add-ssh-key-to-pantheon-and-create-machine-token)
  - [(Step 8) Pull "production" database to local](#step-8-pull-production-database-to-local)
  - [(Step 9) Run database updates, revert Features and clear caches](#step-9-run-database-updates-revert-features-and-clear-caches)
  - [(Step 10) Test your site](#step-10-test-your-site)
  - [(Step 10) Resolve broken images](#step-10-resolve-broken-images)
    - [Proxying using Resource Override](#proxying-using-resource-override)
  - [(Step 11) Login to site](#step-11-login-to-site)
- [Lando basics](#lando-basics)
- [Lando project specific commands](#lando-project-specific-commands)
  - [lando pull](#lando-pull)
  - [lando drupal-config-import](#lando-drupal-config-import)
  - [lando env-deploy](#lando-env-deploy)
  - [lando env-config-import](#lando-env-config-import)
- [Drush](#drush)
  - [Useful Drush commands](#useful-drush-commands)
    - [Clear caches](#clear-caches)
    - [Run database updates](#run-database-updates)
    - [List modules](#list-modules)
    - [Drupal error log](#drupal-error-log)
- [Terminus](#terminus)
  - [Using Drush with Terminus](#using-drush-with-terminus)
- [Development process](#development-process)
  - [Using Features](#using-features)
  - [Pulling database to local](#pulling-database-to-local)
  - [Creating a new feature branch](#creating-a-new-feature-branch)
  - [Exporting config and committing code](#exporting-config-and-committing-code)
  - [Pushing a new branch](#pushing-a-new-branch)
  - [Creating a Pull Request](#creating-a-pull-request)
  - [Merging a Pull Request](#merging-a-pull-request)
- [Deployment](#deployment)
  - [Dev deployment process](#dev-deployment-process)
  - [Test deployment process](#test-deployment-process)
  - [Live deployment process](#live-deployment-process)
- [Checking for Drupal core and contrib module updates](#checking-for-drupal-core-and-contrib-module-updates)
- [Updating Drupal core](#updating-drupal-core)
  - [Branch off of master](#branch-off-of-master)
  - [Download update using Drush](#download-update-using-drush)
  - [Reapply core patches](#reapply-core-patches)
  - [Run database updates](#run-database-updates-1)
  - [Verify and commit](#verify-and-commit)
- [Updating Drupal contrib modules](#updating-drupal-contrib-modules)
  - [Download update using Drush](#download-update-using-drush-1)
  - [Reapply module patches](#reapply-module-patches)
    - [Current (known) contrib module patches:](#current-known-contrib-module-patches)
    - [Contrib modules known to NOT have been patched or hacked by previous devs:](#contrib-modules-known-to-not-have-been-patched-or-hacked-by-previous-devs)
  - [Verify and commit](#verify-and-commit-1)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# Purpose

Drupal 7 website for DoveLewis AtDove (https://www.atdove.org).

# Warning

We inherited this site. There is almost nothing about this that you should use as an example of how to build a Drupal site. It's a total mess. Be very careful when making any change, because it will very likely have unintended side effects. Good luck!

# Project branch strategy
    master                            :: Push automatically deploys to Dev env.
    DAOM-ticket-number-description    :: Feature branch corresponding to a Jira ticket. Branch off of master and create a PR to merge back in.

# Recommended versions
    PHP         :: 7.3 (installed automatically by Lando)
    Drush       :: 8.x (installed automatically by Lando)

# Codebase

The repo exists on Pantheon and is forked on GitHub. Do not clone the Pantheon repo. See ["Local dev setup using Lando"](#local-dev-setup-using-lando).

* GitHub: https://github.com/HelloWorldDevs/atdove
* Pantheon: https://dashboard.pantheon.io/sites/d2e44185-85d8-4ffa-a0b3-a8c4078abda8#dev

# Hosting

This site is hosted on Pantheon. Pantheon provides a dashboard from which you can create database backups etc.
See [External Resources](#external-resources) for a link to Pantheon.

* Pantheon:
  * https://dashboard.pantheon.io/sites/d2e44185-85d8-4ffa-a0b3-a8c4078abda8#dev
* Environments:
  * Local: https://atdove-d7.lando
  * Dev: https://dev-atdove-d7.pantheonsite.io/
  * Staging/Test: https://test-atdove-d7.pantheonsite.io/
  * Live: https://www.atdove.org

# External Resources

* Jira:
  * https://helloworlddevs.atlassian.net/secure/RapidBoard.jspa?rapidView=65&projectKey=DAOM
* Confluence:
  * https://helloworlddevs.atlassian.net/wiki/spaces/DOV/pages/1498415105/AtDove+atdove.org


# Local dev setup using Lando

## (Step 1) Get a Pantheon account

Ask another developer to invite you to the Pantheon team.

## (Step 2) Install Lando and Docker Desktop

Follow the recommended instructions for installing Lando if you haven't already. Docker Desktop will be installed as well.

https://docs.lando.dev/basics/installation.html#macos

## (Step 3) Git clone the repo

`git clone` the GitHub repo into whichever directory you prefer.

`cd` into the repo/project root.

## (Step 4) Configure Git

Modify your `.git/config` to match the following, replacing any existing remotes or branches. This is an attempt to keep the Pantheon and GitHub repos in sync.

```
[checkout]
    defaultRemote = github
[push]
    default = current
[remote "github"]
    url = git@github.com:HelloWorldDevs/atdove.git
    fetch = +refs/heads/*:refs/remotes/github/*
    pushurl = git@github.com:HelloWorldDevs/atdove.git
    pushurl = ssh://codeserver.dev.d2e44185-85d8-4ffa-a0b3-a8c4078abda8@codeserver.dev.d2e44185-85d8-4ffa-a0b3-a8c4078abda8.drush.in:2222/~/repository.git
[remote "pantheon"]
    url = ssh://codeserver.dev.d2e44185-85d8-4ffa-a0b3-a8c4078abda8@codeserver.dev.d2e44185-85d8-4ffa-a0b3-a8c4078abda8.drush.in:2222/~/repository.git
    fetch = +refs/heads/*:refs/remotes/pantheon/*
    pushurl = git@github.com:HelloWorldDevs/atdove.git
    pushurl = ssh://codeserver.dev.d2e44185-85d8-4ffa-a0b3-a8c4078abda8@codeserver.dev.d2e44185-85d8-4ffa-a0b3-a8c4078abda8.drush.in:2222/~/repository.git
[branch "master"]
    remote = github
    merge = refs/heads/master
    rebase = true
```

For more information, see:
https://helloworlddevs.atlassian.net/l/c/mq3b1yBg

## (Step 5) Configure /etc/hosts

Edit `/etc/hosts` on your local machine. Add these lines:

```
127.0.0.1				atdove-d7.lando
```

Normally Lando will create site URLs in the format *.lndo.site. Because of the proxy settings we have in `.lando.yml`, those won’t be created. Instead we’ll have this nicer URL, but the trade off is we have to add it to our `/etc/hosts` file.

## (Step 6) Lando start

Run:

```
lando start
```

The first time you run this it will take a while. Eventually you’ll be given some URLs to access the site, however they will not work yet because we haven’t pulled the database yet. Lando attempts to create URLs based on the available ports on your machine. The URLs that will be most reliable/consistent will be https://atdove-d7.lando or http://atdove-d7.lando, however you may find that they are instead https://atdove-d7.lando:444/ or http://atdove-d7.lando:8000/. Make note of whatever URLs you’re given so we can try them later.

## (Step 7) Add SSH key to Pantheon and create machine token

Follow Pantheon's documentation:

* Add your SSH public key to your Pantheon account.
  * https://pantheon.io/docs/ssh-keys#add-your-ssh-key-to-pantheon
* Create a Machine Token in your Pantheon account.
  * https://pantheon.io/docs/machine-tokens#create-a-machine-token
  * Copy and paste the machine token somewhere so you can use it later.
  * It would make sense to name the token "Atdove - Lando".
  * When asked to run a `terminus` command to authenticate, preface it with `lando terminus`.

## (Step 8) Pull "production" database to local

To pull the database from a remote Pantheon environment, run:

```
lando pull
```

* You may be asked to authenticate using the machine token you created.
* You'll be asked whether/where you want to pull code, database and files from. You can select "none" for anything you want to skip.
  * Choose "none" for code (use `git pull` instead).
  * Choose "live" for database.
  * Choose "none" for files. (you may be able to get by without files and save some space on your machine)

## (Step 9) Run database updates, revert Features and clear caches

To run database updates, revert Features and clear caches, run:

```
cd web
```

```
lando drupal-config-import
```

This is a wrapper around `drush updb -y; drush fra -y; drush cc all`. You could call these directly instead.

_Always run these commands after pulling the database from a remote environment._

## (Step 10) Test your site

Go to one of the URLs you were given by `lando start`. If using Chrome you may have to use the “Advanced” option to bypass the SSL warning. For some reason Chrome does not like the way Lando signs SSL certificates. You will only have to do this the first time you visit the site after running lando start.

The site should load, however most images will be broken. Lets fix that.

## (Step 10) Resolve broken images

### Proxying using Resource Override

Because this is a large site and some of the images the client uploaded are insanely large,
it is not recommended to pull the `/web/sites/default/files` directory from production.

Instead, we highly recommend you save some space on your machine by proxying images from production using the [Resource Override Chrome plugin](https://helloworlddevs.atlassian.net/wiki/spaces/HWD/pages/1208877057/Developer+Tools#Resource-Override).

## (Step 11) Login to site

* Login to site by going to /user or by clicking "Scrub In".
* To get credentials, search LastPass for "atdove.org: Admin role user".

# Lando basics

https://helloworlddevs.atlassian.net/wiki/spaces/HWD/pages/1635418113/Lando+basics

# Lando project specific commands

Run `lando` for a full list of commands.

## lando pull
```
lando pull
```
Provided by Lando Pantheon recipe.

Pulls the database or files from a remote Pantheon environment.

## lando drupal-config-import
```
lando drupal-config-import
```
Runs database updates, reverts Features and clears caches on your local Lando environment.

Run this after pulling the database and/or before starting a new ticket.

## lando env-deploy
```
lando env-deploy
```
Deploys to Test or Live Pantheon environment (deploys code, updates database, reverts Features and clears caches).

## lando env-config-import
```
lando env-config-import
```
Runs database updates, reverts Features and clears caches on a remote Pantheon environment.

# Drush

*NOTE: In order to run a Drush command, you must be in `/web/sites/default`.*

Drush is a CLI tool for Drupal. Lando installs it automatically and you can use it by running:

```
lando drush COMMAND
```

## Useful Drush commands

### Clear caches

```
lando drush cc all
```

### Run database updates

```
lando drush updb -y
```

### List modules

```
lando drush pm-list
```

### Drupal error log

Shows you Drupal error log in real time.

```
lando drush wd-show --tail
```

# Terminus

Terminus is a CLI tool for Pantheon. Lando installs it automatically and you can use it by running:

```
lando terminus
```

It's likely you'll never have to use Terminus directly. You'll hopefully find that you can accomplish what you need by running `lando` and choosing a command from the list.

## Using Drush with Terminus

You can use Terminus to run Drush commands on different Pantheon environments. The possible environments are dev, test, live or a Multidev environment.

For example, to run a Drush command on the dev environment:

```
terminus drush atdove-d7.dev -- DRUSH_COMMAND
```

# Development process

## Using Features

See documentation in HW Confluence:

https://helloworlddevs.atlassian.net/wiki/spaces/HWD/pages/898826241/Drupal+7+Features+module+overview

## Pulling database to local

_NOTE: You'll really want to avoid pulling the database unless absolutely necessary because it is probably an hour long ordeal._

_It is not recommended to pull the Live database directly_ because the Live database is 3 times the size of the Dev database due to extra cache tables and such. The best option is to first replace the Dev database with the Live database.

Run:
```
lando pull
```
* Choose "none" for code.
* Choose "live" for database.
* Choose "none" for files.

## Creating a new feature branch

* `git checkout master; git pull;`
* Only if necessary, [pull a fresh copy of the Live DB](#pulling-database-to-local).
* Run `lando drush updb -y` to ensure that database updates have been run.
* Run `lando drush fra -y` to revert Features.
* Run `git checkout -b DAOM-TICKET_NUMBER` to create a new feature branch.

## Exporting config and committing code

* Commit your code changes. Please start your commit message with "DAOM-TICKET_NUMBER:".
* Follow the [documentation for Features](https://helloworlddevs.atlassian.net/wiki/spaces/HWD/pages/898826241/Drupal+7+Features+module+overview) to update config for any Features that have been modified, or export any new config.

## Pushing a new branch

Because of the unusual Git config for this project, when you run `git push` to push
a new branch for the first time, you are not given a helpful message.
Here is the pattern to follow:
`git push -u github DAOM-15-retina-images`

## Creating a Pull Request

You can create PRs using GitHub: https://github.com/HelloWorldDevs/atdove/pulls

Ensure that you've branched off of `master` to create your feature branch,
and that your PR merges your feature branch back into `master`.

## Merging a Pull Request

Because we have two repos that we're trying to keep in sync (GitHub and Pantheon), there are a few more steps
after you've clicked the "Merge pull request" button in GitHub.

Your `master` branch must be configured in `.git/config` like this:

```
[branch "master"]
  remote = github
  merge = refs/heads/master
```

Run this after merging a PR:

```
git checkout master; git pull; git push;
```

Assuming this pushed without error, the merged commits from GitHub have now been pushed to Pantheon
and the two repos should be in sync. *If you do not do this, the commits won't actually be deployed to Dev env.*

If there was an error, see:
https://helloworlddevs.atlassian.net/l/c/mq3b1yBg

# Deployment

The sites/environments are hosted on Pantheon:

https://dashboard.pantheon.io/sites/d2e44185-85d8-4ffa-a0b3-a8c4078abda8#dev

A Pantheon QuickSilver script runs database updates, reverts Featurs and clears caches after
certain Pantheon workflows occur. This is configured in `pantheon.yml` and `web/private/scripts/quicksilver/drush_update_import/drush_update_import.php`.

## Dev deployment process

* `master` branch deploys to the Dev environment when pushed to.
* Either push to the `master` branch or merge a PR into `master`.
* Optionally, verify database updates and Features revert were run:
    ```
    lando env-config-import
    ```

## Test deployment process

* To deploy commits that are already on Dev to Test, run:
    ```
    lando env-deploy
    ```
* Optionally, verify database updates and Features revert were run:
    ```
    lando env-config-import
    ```

## Live deployment process

* To deploy commits that are already on Test to Live, run:
    ```
    lando env-deploy
    ```
* Optionally, verify database updates and Features revert were run:
    ```
    lando env-config-import
    ```

# Checking for Drupal core and contrib module updates

You can check for updates to Drupal core and contrib modules by running:

```
lando drush ups
```

To check specifically for security updates run:

```
lando drush ups --security-only
```

# Updating Drupal core

## Branch off of master

Checkout and branch off of `master`:

```
git checkout master; git pull; git checkout -b core-update-TODAYS-DATE
```

## Download update using Drush

To update core, run:

```
lando drush pm-update drupal
```

Updating will overwrite changes to `.htaccess` that we need. Run `gd .htaccess` to check what changes have been made. If there are additions,
it may make sense to copy them and readd them manually, but first undo all the changes to `.htaccess`:

 ```
 git checkout .htaccess
 ```

Now if you deem it necessary, you may manually readd the additions to `.htaccess` the update was trying to make.

You may also need to do the same for `robots.txt` if changes were made there.

Now reapply the core patch(es) described in the next section.

## Reapply core patches

After updating Drupal core, you need to reapply any patches to core that exist inside `/patches/drupal`.

Currently there are no core patches applied.

## Run database updates

To run database updates, run:

```
lando drush updb -y
```

To check the version of core reported is what you expect, run:

```
lando drush status
```

## Verify and commit

Poke around the site a bit to ensure nothing is obviously broken. If all looks ok, you may commit and push your changes.

Now create a PR to merge your `core-update-TODAYS-DATE` branch into `master`.

Once the PR has passed code review, merge the PR and [deploy](#deployment).

Ensure that each environment is functioning properly.

# Updating Drupal contrib modules

## Download update using Drush

To update a module, run from `/web/sites/default`:

```
lando drush pm-update MODULE_NAME
```

## Reapply module patches

_WARNING:_ Due to previous devs, some contrib modules are patched without the patch existing in the `/patches` directory.
They sometimes put patches in the module directory itself, or sometimes they didn't even make a patch at all, but just hacked at the module without creating any record of it.
After updating a modules, run `git diff` and search for a `.patch` file being removed. If you find one, move it to the `/patches` directory, then attempt to reapply it. Please update this README if you find one.

Patches to various contrib modules can be found in the `/patches` directory.
After updating a module, be sure to reapply any patches for it.

### Current (known) contrib module patches:

* views_php
  1. `/patches/views_php/views_php-3055655-14.patch`
      * To reapply this patch run from `/web`:
        * `patch -p1 < ../patches/views_php/views_php-3055655-14.patch`
      * For more information: https://www.drupal.org/project/views_php/issues/3055655
* commerce_discount
  1. `/patches/commerce_discount/commerce_discount-n3174880-6.patch`
      * To reapply this patch run from `/web`:
        * `patch -p1 < ../patches/commerce_discount/commerce_discount-n3174880-6.patch`
      * For more information: https://www.drupal.org/project/commerce_discount/issues/3174880
* commerce_license_billing
  1. `/patches/commerce_license_billing/commerce_license_billing-outlier.patch`
      * To reapply this patch run from `/web`:
        * `patch -p1 < ../patches/commerce_license_billing/commerce_license_billing-outlier.patch`
      * This is a patch we generated based on the previous devs hacking away at this module. Although we generated the patch, we did not write the code.
* openid_connect
  1. `/patches/openid_connect/openid_connect-atdove_customizations.patch`
      * To reapply this patch run from `/web`:
        * `patch -p1 < ../patches/openid_connect/openid_connect-atdove_customizations.patch`
      * This patch is made up of changes made by the previous devs and some from us. We recommend avoiding updating openid_connect unless it is a security update.
* flag
  1. `/patches/flag/flag-array-check-1925922-169.patch`
    * To reapply this patch run from `/web`:
      * `patch -p1 < ../patches/flag/flag-array-check-1925922-169.patch`
* print
  1. `/patches/print/print-fix-autoload-path.patch`
    * To reapply this patch run from `/web`:
      * `patch -p1 < ../patches/print/print-fix-autoload-path.patch`

### Contrib modules known to NOT have been patched or hacked by previous devs:

These are modules that you can update as needed without worrying about whether you're deleting code hacked into the module by the previous devs.

* commerce_license

## Verify and commit

Poke around the site a bit to ensure nothing is obviously broken. If all looks ok, you may commit and push your changes.

Now create a PR to merge your `core-update-TODAYS-DATE` branch into `master`.

Once the PR has passed code review, merge the PR and [deploy](#deployment).
