#!/usr/bin/env bash

# This file is configured in .lando.yml. Run: lando env-config-import.
# It will run database updates, revert features and clear caches
# on the chosen environment.

NORMAL="\033[0m"
RED="\033[31m"
YELLOW="\033[32m"
ORANGE="\033[33m"
PINK="\033[35m"
BLUE="\033[34m"

echo
echo -e "${RED}WARNING: This will affect a remote Pantheon environment."
echo
echo -e "${ORANGE}Are you sure you want to run database updates, revert features and clear caches on a remote Pantheon environment? (y/n):${BLUE}"
echo
read REPLY
if [[ ! "$REPLY" =~ ^[Yy]$ ]]
then
  exit 1
fi

echo
echo -e "${ORANGE}Enter the environment to run database updates, import config and clear caches on (dev/test/live)."
echo
read REPLY_ENV
if [ "$REPLY_ENV" = "live" ] || [ "$REPLY_ENV" = "test" ] || [ "$REPLY_ENV" = "dev" ]
then
  if [ "$REPLY_ENV" = "live" ]
  then
    echo
    echo -e "${ORANGE}Are you sure you want to run database updates, revert features and clear caches on live/prod? This will wipe out any config changes that are currently on live/prod. (y/n):${BLUE}"
    echo
    read REPLY_CONFIRM
    if [[ ! "$REPLY_CONFIRM" =~ ^[Yy]$ ]]
    then
      exit 1
    fi
  fi

  echo
  echo -e "${YELLOW}Running database updates, reverting features and clearing caches on $REPLY_ENV environment...${NORMAL}"
  echo
  terminus remote:drush atdove-d7."$REPLY_ENV" -- updb -y

  echo
  echo -e "${YELLOW}Reverting features...${NORMAL}"
  echo
  terminus remote:drush atdove-d7."$REPLY_ENV" -- fra -y

  echo
  echo -e "${YELLOW}Clearing caches...${NORMAL}"
  echo
  terminus remote:drush atdove-d7."$REPLY_ENV" -- cc all

  echo
  echo -e "${YELLOW}Running drush fl and status so you know what's up...${NORMAL}"
  echo
  terminus remote:drush atdove-d7."$REPLY_ENV" -- fl
  terminus remote:drush atdove-d7."$REPLY_ENV" -- status
else
  echo
  echo -e "${RED}Please provide a valid env. Choose between 'dev', 'test', or 'live'.${NORMAL}"
  echo
  exit 1
fi
